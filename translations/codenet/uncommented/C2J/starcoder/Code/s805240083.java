
import java.util.*;

public class Main {
  public static void main(String[] args) {
    int n,q,i,T=0;
    Scanner in = new Scanner(System.in);
    n=in.nextInt();
    q=in.nextInt();
    P[] Q=new P[n];
    for (i=0;i<n;i++){
      Q[i]=new P();
      Q[i].name=in.next();
      Q[i].t=in.nextInt();
    }

    while(n!=0){
      P a=Q[0];
      if(a.t>q){
        a.t=a.t-q;
        T+=q;
        Q[0]=a;
      }
      else{
        T=T+a.t;
        System.out.println(a.name+" "+T);
        n--;
        for (i=0;i<n;i++){
          Q[i]=Q[i+1];
        }
      }
    }
  }
}

