import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, c, k, b; // Declare variables to store input, counters, and temporary values

        // Start a while loop to read input
        while (scanner.hasNextInt()) { // Read an integer 'a' from the input
            a = scanner.nextInt(); // Read the integer value into 'a'
            c = 0; // Initialize counter 'c' to 0
            k = 0; // Initialize counter 'k' to 0

            if (a < 3) { // Check if 'a' is less than 3
                System.out.println("0"); // Print 0 if 'a' is less than 3
            } else {
                b = a; // Store the initial value of 'a' in 'b' for later use
                while (a-- > 0) { // Decrement 'a' until it becomes 0
                    b--; // Decrement 'b' in each iteration
                    c++; // Increment 'c' in each iteration
                    if (c == 3) { // Check if 'c' equals 3
                        k++; // Increment 'k'
                        c = 0; // Reset 'c' to 0
                    }
                }
                System.out.println(k); // Print the number of times 'c' reset to 0
            }
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
