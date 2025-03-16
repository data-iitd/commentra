import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for taking input
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input from the user and assign it to the variable n
        int n = scanner.nextInt();
        
        // Initialize a counter variable x to 1
        int x = 1;

        // While loop starts
        while (true) {
            // Check if the log base 2 of n is an integer yet
            if (isPowerOfTwo(n)) {
                break;
            }

            // Increment the counter variable x by 1
            x += 1;

            // Update the value of n by subtracting 2 raised to the power of the current log base 2 of n
            n -= (int) Math.pow(2, (int) (Math.log(n) / Math.log(2)));
        }

        // Print the output value of x
        System.out.println(x);
        
        // Close the scanner
        scanner.close();
    }

    // Helper method to check if a number is a power of two
    private static boolean isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
}
// <END-OF-CODE>
