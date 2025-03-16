
import java.util.*;
import java.io.*;
class s814403222{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    while(sc.hasNextInt()){
      int n = sc.nextInt();
      if(n == 0) break;
      int m;
      int[][] d = new int[33][n];
      int[] c = new int[n];
      String[] s = new String[n];
      for(int i = 0; i < n; i++){
	c[i] = 0;
	s[i] = sc.next();
	m = sc.nextInt();
	for(int j = 0; j < m; j++){
	  int a = sc.nextInt();
	  c[i] += n - d[a][0];
	  for(int k = 0; k < d[a][0]; k++){
	    c[d[a][k]]--;
	  }
	  d[a][d[a][0]++] = i;
	}
      }
      int max = 0;
      int maxi = 0;
      for(int i = 0; i < n; i++){
	if(max < c[i]){
	  max = c[i];
	  maxi = i;
	}
      }
      System.out.println(c[maxi] + " " + s[maxi]);
    }
  }
}
