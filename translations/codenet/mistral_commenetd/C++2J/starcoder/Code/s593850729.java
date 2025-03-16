import java.util.*; // Import the Scanner class

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in); // Create a Scanner object to read input from the console

    int A = input.nextInt(); // Read an integer from the user and store it in variable A
    int B = input.nextInt(); // Read an integer from the user and store it in variable B
    int C = input.nextInt(); // Read an integer from the user and store it in variable C
    int X = input.nextInt(); // Read an integer from the user and store it in variable X

    int cnt = 0; // Initialize counter variable cnt to 0
    for (int a = 0; a <= A; a++) { // Start of the outermost for loop, iterating from 0 to A
      for (int b = 0; b <= B; b++) { // Start of the inner for loop, iterating from 0 to B
        for (int c = 0; c <= C; c++) { // Start of the innermost for loop, iterating from 0 to C
          int total = 500*a + 100*b + 50*c; // Calculate the total value based on the current values of a, b, and c
          if (total == X) cnt++; // If the total value equals X, increment the counter variable cnt
        }
      }
    }
    System.out.println(cnt); // Output the final value of the counter variable cnt to the console
  }
}
