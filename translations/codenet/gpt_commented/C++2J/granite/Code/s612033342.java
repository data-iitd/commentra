
import java.util.*;

class s612033342 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    int k = sc.nextInt();
    int[][] hw = new int[h][w];
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        char c = sc.next().charAt(0);
        if (c == '#') hw[i][j] = 1;
      }
    }
    int sum = 0;
    for (int i = 0; i < Math.pow(2, h); i++) {
      for (int j = 0; j < Math.pow(2, w); j++) {
        int count = 0;
        for (int x = 0; x < h; x++) {
          for (int y = 0; y < w; y++) {
            if (((i >> x) & 1) == 1 && ((j >> y) & 1) == 1 && hw[x][y] == 1) count++;
          }
        }
        if (count == k) sum++;
      }
    }
    System.out.println(sum);
  }
}
