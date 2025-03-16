import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declare variables a, b, c, and d of type int
    int a, b, c, d;

    // Create a Scanner object to read input from standard input
    Scanner scanner = new Scanner(System.in);

    // Read values of variables a, b, c, and d from standard input
    a = scanner.nextInt();
    b = scanner.nextInt();
    c = scanner.nextInt();
    d = scanner.nextInt();

    // Calculate the difference between a and c, and the difference between b and d
    long difference_ab = a - c;
    long difference_cd = b - d;

    // Multiply the differences and print the result to standard output
    System.out.println(difference_ab * difference_cd);
  }
}

