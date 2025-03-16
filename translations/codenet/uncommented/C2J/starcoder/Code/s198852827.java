import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int N,t,x,y,nx=0,ny=0,nt=0;
    int i,j,k,tmp;
    N=sc.nextInt();
    for(i=0;i<N;i++){
      t=sc.nextInt();
      x=sc.nextInt();
      y=sc.nextInt();
      tmp=t-nt-(Math.abs(x-nx)+Math.abs(y-ny));
      if(tmp<0 || tmp%2!=0){
	System.out.println("No");
	return;
      }
    }
    System.out.println("Yes");
  }
}
