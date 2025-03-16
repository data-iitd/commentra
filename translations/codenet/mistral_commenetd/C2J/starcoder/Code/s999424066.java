import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int a = input.nextInt();
    int b = input.nextInt();
    int c = input.nextInt();
    int x = input.nextInt();
    int y = input.nextInt();
    c *= 2;
    if (a + b <= c) {
      System.out.println(a * x + b * y);
    } else {
      if (x <= y) {
        if (b <= c) {
          System.out.println(c * x + (y - x) * b);
        } else {
          System.out.println(c * y);
        }
      } else {
        if (a <= c) {
          System.out.println(c * y + (x - y) * a);
        } else {
          System.out.println(c * x);
        }
      }
    }
  }
}
