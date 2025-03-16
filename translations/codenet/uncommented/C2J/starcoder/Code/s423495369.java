import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int A, B, C;

    A = in.nextInt();
    B = in.nextInt();
    C = in.nextInt();

    if (A < C && C < B) {
      System.out.println("Yes");
    } else if (A > C && C > B) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}

