import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    while(cin.hasNext()){
      int n = cin.nextInt();
      if(n == 0) break;
      int m;
      int[] d = new int[33];
      for(int i = 0; i < 33; i++) d[i] = 0;
      P[] v = new P[n];
      for(int i = 0; i < n; i++){
	v[i] = new P(0, "");
	cin.next();
	m = cin.nextInt();
	for(int j = 0; j < m; j++){
	  int a = cin.nextInt();
	  v[i].first += n - d[a];
	  d[a]++;
	}
      }
      Arrays.sort(v);
      System.out.println(v[0].first + " " + v[0].second);
    }
  }
}
