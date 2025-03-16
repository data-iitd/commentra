
public class Main {
  public static void main(String[] args) {
    int A, B, flag = 0;
    Scanner sc = new Scanner(System.in);
    A = sc.nextInt();
    B = sc.nextInt();

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

