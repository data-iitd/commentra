
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    while (n != 0) {
      int[][] d = new int[33][];
      for (int i = 0; i < 33; i++) {
        d[i] = new int[n];
      }
      int[][] v = new int[n][2];
      for (int i = 0; i < n; i++) {
        v[i][0] = 0;
        String name = sc.next();
        int m = sc.nextInt();
        for (int j = 0; j < m; j++) {
          int a = sc.nextInt();
          v[i][0] += n - d[a].length;
          for (int k = 0; k < d[a].length; k++) {
            v[d[a][k]][0]--;
          }
          d[a][d[a].length] = i;
        }
      }
      Arrays.sort(v, new Comparator<int[]>() {
        public int compare(int[] a, int[] b) {
          return a[0] - b[0];
        }
      });
      System.out.println(v[0][0] + " " + v[0][1]);
      n = sc.nextInt();
    }
  }
}

