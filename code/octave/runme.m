callback 

DCallback=@() subclass(example.Callback(), 'response',@(self) printf("response from octave.\n"));
callback = DCallback().__disown();
caller = example.Caller(callback);
caller.request();

