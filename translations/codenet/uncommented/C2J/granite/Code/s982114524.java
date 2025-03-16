
import java.util.Scanner;
public class s982114524{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int i, N, x;
    x = 0;
    N = sc.nextInt();
    for (i = 1; i <= N; i++) {
      x += i;
    }
    System.out.println(x);
  }
}
// 