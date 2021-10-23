package TD3.TD3JAVA;
public class IncDec{
    private int val;
    public IncDec(int val){
        this.val =val;
    }
    public int in(){
        System.out.printf("valeur in %d\n",val);
      return val++;
    }
    public int dec(){
        System.out.printf("valeur dec %\n",val);
     return val--;
    }
    public int getVal(){
        return this.val;
    }
}