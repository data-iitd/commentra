
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    String t = sc.nextLine();
    s += s;
    System.out.println(s.contains(t) ? "Yes" : "No");
  }
}

