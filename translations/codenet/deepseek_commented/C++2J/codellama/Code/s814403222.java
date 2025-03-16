import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNextInt()) {
      int n = sc.nextInt();
      if (n == 0) break;
      int[][] d = new int[33][];
      for (int i = 0; i < 33; i++) d[i] = new int[n];
      for (int i = 0; i < n; i++) {
        int m = sc.nextInt();
        for (int j = 0; j < m; j++) {
          int a = sc.nextInt();
          d[a][j] = i;
        }
      }
      int[] v = new int[n];
      for (int i = 0; i < n; i++) {
        v[i] = 0;
        for (int j = 0; j < d[i].length; j++) {
          v[i] += n - d[d[i][j]].length;
          for (int k = 0; k < d[d[i][j]].length; k++) {
            v[d[d[i][j]][k]]--;
          }
        }
      }
      Arrays.sort(v);
      System.out.println(v[0] + " " + (n - v[0]));
    }
  }
}

