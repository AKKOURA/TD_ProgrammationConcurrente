package TD2;

public class TacheChaine  implements Runnable{
    String chaine;
    
    public TacheChaine(String chaine) {
        this.chaine = chaine;
    }

    @Override
    public void run() {
     System.out.println(chaine);
        
    }

}