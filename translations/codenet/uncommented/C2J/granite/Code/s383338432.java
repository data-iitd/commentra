
import java.util.Scanner;

public class s383338432{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int height = scanner.nextInt();
    int width = scanner.nextInt();
    String inputStr;
    for(int i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();
    for(int i = 0; i < height; i++) {
      inputStr = scanner.next();
      System.out.println("#" + inputStr + "#");
    }
    for(int i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();
  }
}
