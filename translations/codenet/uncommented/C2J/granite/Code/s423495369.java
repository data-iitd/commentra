
import java.util.Scanner;

public class s423495369{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    int C = scanner.nextInt();

    if (A < C && C < B) {
      System.out.println("Yes");
    } else if (A > C && C > B) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
// 