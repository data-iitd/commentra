import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    while(sc.hasNextInt()){
      int n = sc.nextInt();
      if(n == 0) break;
      int[][] d = new int[33][];
      for(int i = 0; i < 33; i++){
	d[i] = new int[n];
	for(int j = 0; j < n; j++){
	  d[i][j] = 0;
	}
      }
      String[] s = new String[n];
      for(int i = 0; i < n; i++){
	s[i] = sc.next();
	int m = sc.nextInt();
	for(int j = 0; j < m; j++){
	  int a = sc.nextInt();
	  d[a][i] = 1;
	}
      }
      int[][] v = new int[n][2];
      for(int i = 0; i < n; i++){
	v[i][0] = 0;
	for(int j = 0; j < n; j++){
	  if(d[j][i] == 0){
	    v[i][0]++;
	  }
	}
      }
      Arrays.sort(v, new Comparator<int[]>(){
	public int compare(int[] a, int[] b){
	  if(a[0] == b[0]){
	    return a[1].compareTo(b[1]);
	  }
	  return a[0] - b[0];
	}
      });
      System.out.println(v[0][0] + " " + v[0][1]);
    }
  }
}
