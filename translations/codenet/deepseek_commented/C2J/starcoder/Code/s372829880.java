import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int x, a;
    x = input.nextInt();
    a = input.nextInt();
    System.out.println((x >= a) * 10);
  }
}
