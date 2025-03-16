
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    long m = 100000000;
    long M = -100000000;
    long c = 0;
    for (int i = 0; i < n; i++) {
      long a = sc.nextLong();
      if (a > M) {
        M = a;
      }
      if (a < m) {
        m = a;
      }
      c += a;
    }
    System.out.println(m + " " + M + " " + c);
  }
}

