
public class GCD {
  public static void main(String[] args) {
    int x, y, z;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter two integers: ");
    x = sc.nextInt();
    y = sc.nextInt();
    if (x >= y) {
      z = you(x, y);
    } else {
      z = you(y, x);
    }
    System.out.println("The greatest common divisor of " + x + " and " + y + " is: " + z);
  }

  public static int you(int x, int y) {
    int z;
    while (y != 0) {
      z = x % y;
      x = y;
      y = z;
    }
    return x;
  }
}

