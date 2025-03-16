import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Beginning of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input
        int x; // Declare an integer variable named x

        x = scanner.nextInt(); // Read an integer value from the standard input and store it in variable x

        if (x >= 1200) { // Beginning of the if statement block
            System.out.println("ARC"); // Output the string "ARC" to the standard output if the condition is true
        } else { // Beginning of the else statement block
            System.out.println("ABC"); // Output the string "ABC" to the standard output if the condition is false
        }

        scanner.close(); // Close the scanner to prevent resource leaks
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
