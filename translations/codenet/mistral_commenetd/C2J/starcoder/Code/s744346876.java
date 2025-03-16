import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int A = input.nextInt();
    int B = input.nextInt();
    if(A < 10 && B < 10) {
      System.out.println(A * B);
    }
    else {
      System.out.println("-1");
    }
  }
}
