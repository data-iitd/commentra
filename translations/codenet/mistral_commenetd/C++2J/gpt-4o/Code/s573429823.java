import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Define the main method, entry point of the program
        // Declare variables
        long n; // Declare a long integer variable to store the input number
        boolean flg = false; // Declare a boolean variable (flag) and initialize it to false

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the input number
        n = scanner.nextLong();

        // Check if n is less than 4
        if (n < 4) {
            System.out.println("No"); // Print "No" and exit the program
            return; // Exit the main method
        }

        // Check if n can be represented as a sum of two integers, each a multiple of 4 and 7
        for (int i = 0; i <= (n / 4); i++) { // Outer loop: i from 0 to n/4
            for (int j = 0; j <= (n / 7); j++) { // Inner loop: j from 0 to n/7
                if ((i * 4 + j * 7) == n) { // Check if the sum of i*4 and j*7 equals n
                    flg = true; // Set the flag to true if found
                    break; // Exit both loops
                }
            }
            if (flg) break; // Exit the outer loop if flag is true
        }

        // Print the result
        if (flg) {
            System.out.println("Yes"); // Print "Yes" if n can be represented as a sum of two integers, each a multiple of 4 and 7
        } else {
            System.out.println("No"); // Print "No" otherwise
        }

        scanner.close(); // Close the scanner
    }
} // End of Main class
// <END-OF-CODE>
