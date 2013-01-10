package org.freequant.ctp;

import java.lang.System;
import java.io.*;

public class Runmd extends CThostFtdcMdSpi {
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
        InputStream in = Runmd.class.getResource("/" + prefix + name + suffix).openStream();
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
            loadLib("ctp");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private CThostFtdcMdApi api;
    String front;
    String brokerId;
    String userId;
    String password ;
    public Runmd(String front, String brokerId, String userId, String password) {
        this.front = front;
        this.brokerId = brokerId;
        this.userId = userId;
        this.password = password;
        api = CThostFtdcMdApi.createFtdcMdApi("");
        api.registerSpi(this);
        api.registerFront(front);
        api.init();
    }

    public void release() {
        api.release();
    }

    public void join() {
        api.join();
    }

    public void OnFrontConnected() {
        System.out.println("OnFrontConnected");
    }

    public static void main(String[] args) {
        String front = "tcp://asp-sim2-front1.financial-trading-platform.com:26213";
        String broker = "2030";
        String user = "352240";
        String password = "888888";
        Runmd spi = new Runmd(front, broker, user, password);
        spi.release();
    }
}
