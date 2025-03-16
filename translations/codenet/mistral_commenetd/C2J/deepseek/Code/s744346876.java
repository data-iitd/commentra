public class Main {
  public static void main(String[] args) {
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    if(A < 10 && B < 10) {
      System.out.println(A * B);
    }
    else {
      System.out.println(-1);
    }
  }
}
