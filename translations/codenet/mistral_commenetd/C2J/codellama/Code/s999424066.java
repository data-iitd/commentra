
public class Main {
  public static void main(String[] args) {
    int a, b, c, x, y;
    Scanner sc = new Scanner(System.in);
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();
    x = sc.nextInt();
    y = sc.nextInt();

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

