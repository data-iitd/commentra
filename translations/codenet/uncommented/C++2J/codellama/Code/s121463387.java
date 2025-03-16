import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for (int i = 1; i <= n; i++) {
      int x = i;
      String s = String.valueOf(x);
      if (x % 3 == 0 || x % 10 == 3) {
        System.out.print(" " + i);
        continue;
      } else {
        int k = s.length();
        while (k > 0) {
          k--;
          int j = (int) Math.pow(10, k);
          if ((x / j) % 10 == 3) {
            System.out.print(" " + i);
            break;
          }
        }
      }
    }
    System.out.println();
  }
}

