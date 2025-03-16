
import java.util.Scanner;

public class s878644875{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String s = scanner.next();
    String t = scanner.next();
    int hit = 0;
    for (int i = 0; i < 3; i++) {
      if (s.charAt(i) == t.charAt(i)) hit++;
    }
    System.out.println(hit);
  }
}
// 