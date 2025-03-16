import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Loop to read input values from the standard input
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt(); // Read the integer input
            int c = 0; // Initialize c to zero
            int k = 0; // Initialize k to zero

            // Check if the input value is less than 3
            if (a < 3) {
                // If yes, print 0 and exit the loop
                System.out.println("0");
                break;
            }

            int b = a; // Assign the value of input 'a' to variable 'b'

            // Loop to process each digit of the input number 'a'
            while (a-- > 0) {
                b--; // Decrement the value of 'b' by 1
                c++; // Increment the value of 'c' by 1

                // Check if the value of 'c' is equal to 3
                if (c == 3) {
                    // If yes, increment the value of 'k' by 1 and reset the value of 'c' to zero
                    k++;
                    c = 0;
                }
            }

            // Print the value of 'k' as the output
            System.out.println(k);
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
