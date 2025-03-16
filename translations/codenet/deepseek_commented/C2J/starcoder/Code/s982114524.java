import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    int i, N, x;
    x = 0;
    Scanner input = new Scanner(System.in);
    N = input.nextInt();
    for(i = 1; i <= N; i++)
      x += i;
    System.out.println(x);
  }
}
