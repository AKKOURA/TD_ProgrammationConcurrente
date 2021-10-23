package TD2;

public class Main {
    public static void main(String[] arg ) throws InterruptedException {
        String chaine= "Souvent, pour samuser, les hommes dequipage\nPrennent des goelands, vastes oiseaux des mers,\nQui suivent, indolents compagnons de voyage,\nLe navire glissant sur les gouffres amers.\n";
        Thread t1=new Thread(new TacheChaine(chaine));
        t1.start();
        t1.join();


   
    }
    
}
