import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        int i, a, b, s; // Declare variables i, a, b, s of integer type
        int[] count = new int[4]; // Declare an array count of size 4 to store the count of each number

        // Initialize the count array with zeros
        for (i = 0; i < 4; i++) count[i] = 0;

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input

        // Read three pairs of numbers from the user and update the count array accordingly
        for (i = 0; i < 3; i++) {
            a = scanner.nextInt(); // Read the first number a from the user
            b = scanner.nextInt(); // Read the second number b from the user
            count[a - 1]++; // Increment the count of number a in the count array
            count[b - 1]++; // Increment the count of number b in the count array
        }

        // Calculate the product of all counts in the count array
        s = 1;
        for (i = 0; i < 4; i++) s *= count[i];

        // Check if the product of all counts is equal to 4
        if (s == 4) System.out.println("YES"); // If yes, print "YES" to the console
        else System.out.println("NO"); // Else, print "NO" to the console

        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of main method
} // End of Main class
// <END-OF-CODE>
