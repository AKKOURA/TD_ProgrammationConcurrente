package TD3JAVA;

public class Main {
    public static void main(String arg[] ) throws InterruptedException {
        IncDec incdec= new IncDec(0);
        Thread t1=new Thread(new TacheInc(incdec));
        t1.start();
        t1.join();

        Thread t2=new Thread(new TacheDec(incdec));
        t2.start();  
        t2.join();
        System.out.printf("valeur final %d ",incdec.getVal());



        
    }
    
    
}
