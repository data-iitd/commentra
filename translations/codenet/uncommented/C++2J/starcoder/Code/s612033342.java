import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int h = in.nextInt();
    int w = in.nextInt();
    int k = in.nextInt();
    int[][] hw = new int[h][w];
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        char c = in.next().charAt(0);
        if (c == '#') hw[i][j] = 1;
      }
    }
    int sum = 0;
    for (int i = 0; i < (1 << h); i++) {
      for (int j = 0; j < (1 << w); j++) {
        if (count(hw, i, j) == k) sum++;
      }
    }
    System.out.println(sum);
  }

  static int count(int[][] hw, int a, int b) {
    int sum = 0;
    for (int i = 0; i < hw.length; i++) {
      for (int j = 0; j < hw[0].length; j++) {
        if ((a >> i & 1)!= 0 && (b >> j & 1)!= 0 && hw[i][j] == 1) sum++;
      }
    }
    return sum;
  }
}

