public class Main {
  public static void main(String[] args) {
    int A, B, C;

    java.util.Scanner scanner = new java.util.Scanner(System.in);
    A = scanner.nextInt();
    B = scanner.nextInt();
    C = scanner.nextInt();

    if (A < C && C < B) {
      System.out.println("Yes");
    } else if (A > C && C > B) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
