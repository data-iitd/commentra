public class Main {
  public static void main(String[] args) {
    long a, b, c;
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    a = scanner.nextLong();
    b = scanner.nextLong();
    c = scanner.nextLong();

    long d = c - a - b;
    if (d > 0 && (4 * a * b) < d * d)
      System.out.println("Yes");
    else
      System.out.println("No");
  }
}
