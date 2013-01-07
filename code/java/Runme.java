package swigmt;

import java.lang.System;
import java.io.*;

public class Runme extends Callback {
    static private void loadLib(final String name) throws IOException {
        String prefix = "";
        String suffix = "";
        String osName = System.getProperty("os.name");
        if (osName.equals("Linux")) {
            prefix = "lib";
            suffix = ".so";
        } else if (osName.substring(0, 7).equals("Windows")) {
            suffix = ".dll";
        }
        InputStream in = Runme.class.getResource("/" + prefix + name + suffix).openStream();
        File lib = File.createTempFile(name, suffix);
        FileOutputStream out = new FileOutputStream(lib);
        int i;
        byte[] buf = new byte[1024];
        while ((i = in.read(buf)) != -1) {
            out.write(buf, 0, i);
        }
        in.close();
        out.close();
        lib.deleteOnExit();
        System.load(lib.toString());
    }

    static {
        try {
            loadLib("callback-java");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void response() {
        System.out.println("response from java thread" + Thread.currentThread().toString());
    }

    public static void main(String[] args) {
        Callback cb = new Runme();
        Caller caller = new Caller(cb);
        System.out.println("request from java thread" + Thread.currentThread().toString());
        caller.request();
    }
}