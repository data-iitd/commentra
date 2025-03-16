import java.util.Scanner;

public class Main {
    // Define a constant for the modulo value
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        // Initialize a scanner for reading input
        Scanner scanner = new Scanner(System.in);

        // Read the values of h and n from input
        int h = scanner.nextInt();
        int n = scanner.nextInt();
        int a = 0; // Initialize a variable to accumulate the sum of integers

        // Loop to read n integers and accumulate their sum
        for (int i = 0; i < n; i++) {
            a += scanner.nextInt();
        }

        // Check if the accumulated sum is less than h
        if (h > a) {
            // If h is greater than the sum, print "No"
            System.out.println("No");
        } else {
            // Otherwise, print "Yes"
            System.out.println("Yes");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
