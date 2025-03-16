import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input
        int a, b; // Declare two integer variables 'a' and 'b'
        char S;   // Declare a character variable 'S'

        // A while loop that runs indefinitely until the user enters '?' to exit
        while (true) {
            a = scanner.nextInt(); // Read an integer 'a' from the input
            S = scanner.next().charAt(0); // Read a character 'S' from the input
            b = scanner.nextInt(); // Read an integer 'b' from the input

            // Perform arithmetic operations based on the operator 'S'
            if (S == '+') System.out.println(a + b); // If 'S' is '+', print the sum of 'a' and 'b'
            if (S == '-') System.out.println(a - b); // If 'S' is '-', print the difference of 'a' and 'b'
            if (S == '*') System.out.println(a * b); // If 'S' is '*', print the product of 'a' and 'b'
            if (S == '/') System.out.println(a / b); // If 'S' is '/', print the quotient of 'a' and 'b'
            if (S == '?') break; // If 'S' is '?', break out of the loop
        }
        scanner.close(); // Close the scanner to free resources
    }
}
// <END-OF-CODE>
