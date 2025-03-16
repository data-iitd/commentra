
public class Main {
  public static void main(String[] args) {
    int A, B, C;

    Scanner sc = new Scanner(System.in);
    A = sc.nextInt();
    B = sc.nextInt();
    C = sc.nextInt();

    if (A < C && C < B) {
      System.out.println("Yes");
    } else if (A > C && C > B) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}

