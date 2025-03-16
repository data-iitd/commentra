
import java.util.Scanner;

public class s218426876{
    public static void main(String[] args) {
        // Declare variables for iteration, sum, and a flag
        int i, sum = 0;
        int flag = 0; // Note: 'flag' is declared but not used in this code
        char x[] = new char[1002]; // Array to store input strings

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the first input string
        x = scanner.nextLine().toCharArray();

        // Loop to process input until the termination condition is met
        do {
            // Iterate through the characters of the input string
            for (i = 0; i < 1002; i++) {
                // Check for the end of the string (null character)
                if (x[i] == 0) {
                    // Print the sum of the digits in the string
                    System.out.println(sum);
                    break; // Exit the loop if end of string is reached
                } else {
                    // Convert character to integer and add to sum
                    sum += x[i] - 0x30; // '0' is represented by 0x30 in ASCII
                }
            }
            
            // Reset sum for the next input
            sum = 0;

            // Read the next input string
            x = scanner.nextLine().toCharArray();
        } while (x[0]!= 0x30); // Continue until the first character is '0'

        // Close the Scanner object
        scanner.close();
    }
}
