using System;
using System.Threading;

namespace Swigmt
{
    public class DCallback : Callback
    {
        public override void response()
        {
            Console.WriteLine("response from c# in thread " + Thread.CurrentThread.ManagedThreadId);
        }
    }

    public class Runme
    {
        public static void Main()
        {
            using (Callback callback = new Callback())
            {
                Caller caller = new Caller(callback);
                Console.WriteLine("request from c# in thread " + Thread.CurrentThread.ManagedThreadId);
                caller.request();
            }
        }
    }
}
