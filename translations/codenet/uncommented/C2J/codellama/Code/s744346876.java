
public class Main {
  public static void main(String[] args) {
    int A, B;
    Scanner sc = new Scanner(System.in);
    A = sc.nextInt();
    B = sc.nextInt();
    if(A < 10 && B < 10) System.out.println(A * B);
    else System.out.println("-1");
  }
}

