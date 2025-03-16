
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String W = sc.next();
    char[] w = W.toCharArray();
    for (int i = 0; i < w.length; i++) {
      if (i + 1 < w.length && w[i] == w[i + 1]) {
        continue;
      } else {
        System.out.println("No");
        return;
      }
    }
    System.out.println("Yes");
  }
}

