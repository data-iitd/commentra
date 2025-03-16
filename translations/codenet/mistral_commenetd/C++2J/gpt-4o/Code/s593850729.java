import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input
        int A = scanner.nextInt(); // Read user input for variable A
        int B = scanner.nextInt(); // Read user input for variable B
        int C = scanner.nextInt(); // Read user input for variable C
        int X = scanner.nextInt(); // Read user input for variable X

        int cnt = 0; // Initialize counter variable cnt to 0
        for (int a = 0; a <= A; a++) { // Start of the outermost for loop, iterating from 0 to A
            for (int b = 0; b <= B; b++) { // Start of the inner for loop, iterating from 0 to B
                for (int c = 0; c <= C; c++) { // Start of the innermost for loop, iterating from 0 to C
                    int total = 500 * a + 100 * b + 50 * c; // Calculate the total value based on the current values of a, b, and c
                    if (total == X) cnt++; // If the total value equals X, increment the counter variable cnt
                }
            }
        }
        System.out.println(cnt); // Output the final value of the counter variable cnt to the console
        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
