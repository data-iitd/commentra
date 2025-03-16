
import java.util.*; // Import the Scanner class and other utility classes from the java.util package
import static java.lang.System.*; // Import the out and in streams from the System class

public class Main {
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner sc = new Scanner(in); // Create a new Scanner object to read input from the standard input stream

        int n; // Declare an integer variable to store the number of test cases

        // Read the first integer from the standard input
        n = sc.nextInt();

        int d = 0; // Initialize an integer variable to store the sum of the remainders of the input integers when divided by 2

        for (int i = 0; i < n; i++) { // Use a for loop to iterate through the input integers n times
            int num = sc.nextInt(); // Read the next integer from the standard input
            d += num % 2; // Add the remainder of the current integer when divided by 2 to the variable d
        }

        out.println(d % 2 == 0?"YES":"NO"); // Print the result to the standard output stream

        sc.close(); // Close the Scanner object to release the system resources
    }
}