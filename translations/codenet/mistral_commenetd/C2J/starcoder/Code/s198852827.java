
import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    int t,x,y,nx=0,ny=0,nt=0;
    int i,j,k,tmp;
    for(i=0;i<N;i++){
      t=sc.nextInt();
      x=sc.nextInt();
      y=sc.nextInt();
      tmp=t-nt-(Math.abs(x-nx)+Math.abs(y-ny));
      if(tmp<0 || tmp%2){
        System.out.println("No");
        return;
      }
      nx=x;
      ny=y;
      nt=t;
    }
    System.out.println("Yes");
  }
}
