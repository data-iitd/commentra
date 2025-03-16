
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int flag = 0;

    for(int i=1; i<=3; ++i) {
      if((A*B*i)%2 == 1) {
        flag = 1;
        break;
      }
    }

    if(flag) System.out.println("Yes");
    else System.out.println("No");
  }
}

