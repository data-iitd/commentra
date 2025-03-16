
import java.util.Scanner; // Import necessary classes for input and output operations

public class s593850729{ // Define the main class
  public static void main(String[] args) { // The main method is the entry point of the program
    Scanner scanner = new Scanner(System.in); // Create a scanner object to read input from the standard input
    int A = scanner.nextInt(); // Read the value of A from the standard input
    int B = scanner.nextInt(); // Read the value of B from the standard input
    int C = scanner.nextInt(); // Read the value of C from the standard input
    int X = scanner.nextInt(); // Read the value of X from the standard input
    
    int cnt = 0; // Initialize a counter to count the number of combinations
    for (int a = 0; a <= A; a++) { // Iterate over the possible values of a (0 to A)
      for (int b = 0; b <= B; b++) { // Iterate over the possible values of b (0 to B)
        for (int c = 0; c <= C; c++) { // Iterate over the possible values of c (0 to C)
          int total = 500*a + 100*b + 50*c; // Calculate the total value of the coins
          if (total == X) cnt++; // If the total equals X, increment the counter
        }
      }
    }
    System.out.println(cnt); // Output the number of combinations that sum up to X
  }
}
