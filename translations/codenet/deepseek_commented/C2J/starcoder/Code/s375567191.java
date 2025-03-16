import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[][] g = new int[n][n];
    int[] d = new int[n];
    int[] f = new int[n];
    int[] color = new int[n];
    int time = 0;

    for (int i = 0; i < n; i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      for (int j = 0; j < y; j++) {
        int z = sc.nextInt();
        g[x - 1][z - 1] = 1;
      }
    }

    for (int i = 0; i < n; i++) {
      color[i] = 0;
      d[i] = 0;
      f[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      if (color[i] == 0) {
        visit(i, g, d, f, color, time);
        time++;
      }
    }

    for (int i = 0; i < n; i++) {
      System.out.printf("%d %d %d\n", i + 1, d[i], f[i]);
    }
  }

  public static void visit(int u, int[][] g, int[] d, int[] f, int[] color, int time) {
    color[u] = 1;
    d[u] = time;
    for (int i = 0; i < g[u].length; i++) {
      if (g[u][i] == 0)
        continue;
      if (color[i] == 0)
        visit(i, g, d, f, color, time);
    }
    color[u] = 2;
    f[u] = time;
  }
}

