
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long A = sc.nextLong();
    long B = sc.nextLong();
    long C = sc.nextLong();
    long K = sc.nextLong();

    if (A + B >= K) {
      System.out.println(Math.min(A, K));
    } else {
      System.out.println(A - (K - (A + B)));
    }
  }
}

