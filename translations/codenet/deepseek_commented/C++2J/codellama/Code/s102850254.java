// <START-OF-CODE>
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int d = sc.nextInt();
    for (int l = 0; l < d; l++) {
      int n = sc.nextInt();
      if (n == 1) {
        System.out.println("#");
        if (l != d - 1) System.out.println();
        continue;
      }
      char[][] map = new char[n + 2][n + 2];
      for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
          map[i][j] = '#';
          if (i == 0 || j == 0 || i == n + 1 || j == n + 1) map[i][j] = '.';
        }
      }
      visit(map);
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j < map[i].length - 1; j++) {
          System.out.print(map[i][j]);
        }
        System.out.println();
      }
      if (l != d - 1) System.out.println();
    }
  }

  public static void visit(char[][] map) {
    int[] dx = {0, 1, 0, -1};
    int[] dy = {-1, 0, 1, 0};
    int sum = 0, flg = 0;
    int x = 2, y = map.length - 1;
    map[y][x] = ' ';
    int[] ab = {2, 2, 2, 2};

    while (true) {
      sum = 0;
      while (true) {
        if (map[y + dy[flg] * 2][x + dx[flg] * 2] != '#' && map[y + dy[flg]][x + dx[flg]] != ' ') {
          flg++;
          break;
        }
        map[y + dy[flg]][x + dx[flg]] = ' ';
        y = y + dy[flg];
        x = x + dx[flg];
        sum++;
      }
      if (flg == 4) flg = 0;
      if (sum == 0) break;
      ab[0] = ab[1];
      ab[1] = ab[2];
      ab[2] = sum;
      if (ab[0] == 1 && ab[2] == 1 && ab[1] == 1) break;
    }
  }
}
// 