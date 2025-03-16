import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        long n; // Declare a variable n of type long
        long b = 0; // Declare a variable b of type long and initialize it to zero

        n = scanner.nextLong(); // Read a long integer value from the standard input and store it in the variable n

        b = (n * (n - 1)) / 2; // Calculate the sum of numbers from 1 to n-1 and store the result in the variable b

        System.out.println(b); // Print the value of b to the standard output

        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
