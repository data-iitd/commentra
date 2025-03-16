
import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n;
    while(sc.hasNextInt()){
      n = sc.nextInt();
      if(n == 0) break;
      int m;
      String name;
      int a;
      int[] d = new int[33];
      for(int i = 0; i < 33; i++) d[i] = 0;
      for(int i = 0; i < n; i++){
	v[i] = new P(0, "");
	sc.next();
	m = sc.nextInt();
	for(int j = 0; j < m; j++){
	  a = sc.nextInt();
	  v[i].first += n - d[a];
	  for(int k = 0; k < d[a]; k++){
	    v[d[a][k]].first--;
	  }
	  d[a]++;
	}
      }
      Arrays.sort(v, new Comparator<P>(){
	public int compare(P a, P b){
	  return a.first - b.first;
	}
      });
      System.out.println(v[0].first + " " + v[0].second);
    }
  }
}

