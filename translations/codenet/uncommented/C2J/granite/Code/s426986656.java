
import java.util.Scanner;

public class s426986656{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    int flag = 0;

    for(int i=1; i<=3; ++i) {
      if((A*B*i)%2 == 1) {
        flag = 1;
        break;
      }
    }

    if(flag == 1) System.out.println("Yes");
    else System.out.println("No");
  }
}
