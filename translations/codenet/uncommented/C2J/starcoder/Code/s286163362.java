
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n,k,t,i,p,ret=0;

    while(true){

      n = in.nextInt();
      k = in.nextInt();
      if(n == 0 && k == 0)break;

      int[] data = new int[111111];
      int[] seq = new int[222222];

      for(i = 0; i < k; i++){
	t = in.nextInt();
	data[t]++;
      }

      p = 0;
      for(i = 1; i <= n; i++){
	if(data[i] > 0){
	  seq[p]++;
	} else {
	  p+=2;
	}
      }
      p++;

      if(data[0] > 0){
	for(i=0;i<p;i++){
	  ret=Math.max(ret,seq[i]+seq[i+2]+1);
	}
      } else {
	for(i=0;i<p;i++){
	  ret=Math.max(ret,seq[i]);
	}
      }

      System.out.println(ret);
    }
  }
}

