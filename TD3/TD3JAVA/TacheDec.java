package TD3.TD3JAVA;
public class TacheDec implements Runnable {
    
    public IncDec incDec;
  
    public TacheDec(IncDec incdec2) {
        this.incDec=incdec2;
    }
    @Override
    public void run() {
        for(int i=0;i<=20 ; i++){
            this.incDec.dec();
        
        }
       
        
    }
}
