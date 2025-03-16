
import java.util.*;
import java.io.*;

class s391929974{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n;

    while(true){
      n = sc.nextInt();
      if(n==0)break;

      int[] sq = new int[n-1];
      int[] fr = new int[(n-1)/2+1];
      Vector<Integer> com = new Vector<Integer>();
      int tmp;

      for(int i=1;i<n;i++)sq[i-1] = (i*i)%n;

      for(int i=1;i<n;i++){
	boolean f = true;
	for(int j=0;j<com.size();j++){
	  if(com.get(j)==sq[i-1]){
	    f = false;
	    break;
	  }
	}
	if(f)com.add(sq[i-1]);
      }

      for(int i=0;i<=(n-1)/2;i++)fr[i] = 0;

      for(int i=0;i<com.size();i++){
	for(int j=0;j<com.size();j++){
	  if(i!=j){
	    tmp = com.get(i)-com.get(j);
	    if(tmp<0)tmp+=n;
	    if(tmp>(n-1)/2)tmp = n - tmp;
	    fr[tmp]++;
	  }
	}
      }

      for(int i=1;i<=(n-1)/2;i++)System.out.println(fr[i]);
    }
  }
}
