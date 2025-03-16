
import java.util.Scanner;

public class s494952667{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String str = sc.nextLine();
    char[] ch = str.toCharArray();
    for (int i = ch.length - 1; i >= 0; i--) {
      System.out.print(ch[i]);
    }
    System.out.println();
  }
}
// 