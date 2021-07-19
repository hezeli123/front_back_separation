package com.simple.front_back_separation; 

public class java_test {  
  static {  
    System.loadLibrary("java_worker");  
  }  
  
  public static void main(String argv[]) {  
    SWIGTYPE_p_void conf = new SWIGTYPE_p_void();
    Worker wk1 = worker.GetWorker("master");
    Worker wk2 = worker.GetWorker("");
    System.out.println(wk1.Init(conf));
    System.out.println(wk2);
    wk1.Run(conf);
    wk2.Run(conf);
  }  
}

