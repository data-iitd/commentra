import java.util.Scanner; // Import Scanner class for input operations

public class SumOfDigits { // Define the class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int sum; // Initialize integer variable 'sum'
        
        // Read a string from standard input
        System.out.print("Enter a string of digits separated by spaces or newline: ");
        String x = scanner.nextLine(); // Read the entire line of input

        do { // Begin a do-while loop
            sum = 0; // Initialize sum to zero before processing each string

            // Process each character in the string 'x'
            for (int i = 0; i < x.length(); i++) {
                // Check if current character is a digit
                if (Character.isDigit(x.charAt(i))) {
                    // Add the integer value of the character to the sum
                    sum += x.charAt(i) - '0'; // Convert char to int
                }
            }

            // Print the sum of digits in the current string
            System.out.println("Sum of digits in previous string: " + sum);

            // Read next string from standard input
            System.out.print("Enter a string of digits separated by spaces or newline: ");
            x = scanner.nextLine(); // Read the next line of input

        } while (x.charAt(0) != '0'); // Continue the loop until the first character of the input string is '0'

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
