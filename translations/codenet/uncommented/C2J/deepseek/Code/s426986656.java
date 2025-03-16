public class Main {
  public static void main(String[] args) {
    int A, B, flag = 0;
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    A = scanner.nextInt();
    B = scanner.nextInt();

    for(int i=1; i<=3; ++i) {
      if((A*B*i)%2 == 1) {
        flag = 1;
        break;
      }
    }

    if(flag != 0) System.out.println("Yes");
    else System.out.println("No");
  }
}
