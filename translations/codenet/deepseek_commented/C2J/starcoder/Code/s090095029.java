import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    boolean[] r0 = new boolean[n];
    Arrays.fill(r0, false);
    int[] r1 = new int[n];
    int nr1 = 0;
    for (int i = 0; i < m; i++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      if (a > b) {
        int t = a;
        a = b;
        b = t;
      }
      if (a == 1) r0[b - 1] = true;
      if (b == n) r1[nr1++] = a - 1;
    }
    boolean res = false;
    for (int i = 0; i < nr1; i++) {
      if (r0[r1[i]]) res = true;
    }
    System.out.println(res? "POSSIBLE" : "IMPOSSIBLE");
  }
}
