
import java.util.Scanner;

public class s426245140{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String s = scanner.nextLine();
    if ((s.charAt(0) == s.charAt(1) && s.charAt(1) == s.charAt(2)) || (s.charAt(1) == s.charAt(2) && s.charAt(2) == s.charAt(3))) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
