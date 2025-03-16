import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int a, b, c, d, e, max;
    a = in.nextInt();
    b = in.nextInt();
    c = a + b;
    d = a - b;
    e = a * b;
    max = c;
    if (max < d) {
      max = d;
    }
    if (max < e) {
      max = e;
    }
    System.out.println(max);
  }
}
