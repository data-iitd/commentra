
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int i, j, k, L, tmp, d, def, end, aj, max, min;

    while(true){
      int an[] = new int[20], a1[] = new int[6], a2[] = new int[6];
      L = sc.nextInt();
      if(L==0) break;

      aj=sc.nextInt(); end=0;

      for(k=1;k<20;k++){
	for(i=L-1;i>=0;i--,aj/=10){
	  a1[i]=aj%10; a2[i]=aj%10;
	}
	for(i=1;i<L;i++){
	  for(j=1;j<L;j++){
	    if(a1[j-1]<a1[j]){
	      int temp = a1[j-1];
	      a1[j-1] = a1[j];
	      a1[j] = temp;
	    }
	    if(a2[j-1]>a2[j]){
	      int temp = a2[j-1];
	      a2[j-1] = a2[j];
	      a2[j] = temp;
	    }
	  }
	}
	d=1; max=0; min=0;
	for(i=L-1;i>=0;i--,d*=10){
	  max+=(a1[i]%10)*d;
	  min+=(a2[i]%10)*d;
	}
	def=max-min;

	for(i=0;i<k;i++){
	  if(def==an[i]){
	    System.out.println(i+" "+def+" "+(k-i));
	    end=1; break;
	  }
	}
	if(end==1) break;
	an[k]=def; aj=def;
      }
    }
  }
}

