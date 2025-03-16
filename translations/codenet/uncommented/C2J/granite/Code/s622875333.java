
import java.util.Scanner;

class s622875333 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (true) {
      int n = sc.nextInt();
      int r = sc.nextInt();
      if (n == 0 && r == 0) break;
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = n - i;
      }
      for (int i = 0; i < r; i++) {
        int[] b = new int[n];
        for (int j = 0; j < n; j++) {
          b[j] = a[j];
        }
        int p = sc.nextInt();
        int c = sc.nextInt();
        for (int j = 0; j < c; j++) {
          a[j] = b[p - 1 + j];
        }
        for (int j = c; j < c + p - 1; j++) {
          a[j] = b[j - c];
        }
      }
      System.out.println(a[0]);
    }
  }
}
