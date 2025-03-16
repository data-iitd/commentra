// by syu
import java.util.Scanner; // Import Scanner class for reading input
import java.io.*; // Import IO classes for working with input and output

// Entry point of the program
public class Main {
    // Print a line to the console with the given arguments
    public static void Pln(Object... args) {
        System.out.println(String.join(" ", Arrays.stream(args).map(Object::toString).toArray(String[]::new)));
    }

    // Main method
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Create a new Scanner instance for standard input

        // Read two integers n and k from standard input
        int n = in.nextInt();
        int k = in.nextInt();

        // Check if n is divisible by k
        if (n % k == 0) {
            // If n is divisible by k, print 0 to the console
            Pln(0);
        } else {
            // If n is not divisible by k, print 1 to the console
            Pln(1);
        }

        in.close(); // Close the scanner
    }
}
// <END-OF-CODE>
