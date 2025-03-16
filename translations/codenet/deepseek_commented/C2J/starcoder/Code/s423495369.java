import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int A, B, C;

    A = input.nextInt();
    B = input.nextInt();
    C = input.nextInt();

    if (A < C && C < B) {
      System.out.println("Yes");
    } else if (A > C && C > B) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
