
import java.util.Scanner;

public class s860117222{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long b = sc.nextLong();
    long c = sc.nextLong();

    long d = c - a - b;
    if ((d > 0) && ((4 * a * b) < d * d)) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
// 