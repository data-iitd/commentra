import java.util.Scanner; // Import Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n, x; // Declare variables n and x of type int

        n = scanner.nextInt(); // Read an integer value from the standard input and assign it to variable n

        for (int i = 1; i <= n; i++) { // Start a for loop that iterates from 1 to n
            x = i; // Assign the value of i to variable x
            String s = Integer.toString(x); // Convert integer x to string s

            if (x % 3 == 0 || x % 10 == 3) { // Check if x is divisible by 3 or its last digit is 3
                System.out.print(" " + i); // If true, print space followed by i
                continue; // Skip the rest of the loop body and move to the next iteration
            } else { // If x is not divisible by 3 and its last digit is not 3
                int k = s.length(); // Get the size of string s

                while (k > 0) { // Start a while loop that runs as long as the size of string s is greater than 0
                    k = k - 1; // Decrease the size of string s by 1
                    int j = (int) Math.pow(10, k); // Calculate the value of the power of 10 raised to the power of the current digit position

                    if ((x / j) % 10 == 3) { // Check if the digit in the current position of x is 3
                        System.out.print(" " + i); // If true, print space followed by i
                        break; // Exit the while loop and move to the next iteration of the for loop
                    }
                }
            }
        }
        System.out.println(); // Print a newline character after the loop is finished

        scanner.close(); // Close the scanner
    }
} // End of Main class
// <END-OF-CODE>
