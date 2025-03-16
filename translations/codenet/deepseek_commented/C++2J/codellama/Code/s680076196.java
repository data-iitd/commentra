// Step 1: Include necessary headers for input/output operations
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Step 2: Define a type for long long integers to handle large numbers
    long long ll;

    // Step 3: Read input values
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();

    // Step 4: Perform calculations
    int area = (a - c) * (b - d);

    // Step 5: Output the result
    System.out.println(area);
  }
}

