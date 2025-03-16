import java.util.Scanner; // For input operations

public class Main { // Define the main class
    static final int MOD = 1000000007; // Define a constant for modular arithmetic
    static final int MOD9 = 998244353; // Another constant for modular arithmetic
    static final double EPS = 1e-7; // Define a small constant for precision in floating point comparisons

    public static void main(String[] args) { // The main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int tc = scanner.nextInt(); // Read the first integer
        int n = scanner.nextInt(); // Read the second integer
        int m = scanner.nextInt(); // Read the third integer
        int fl = 0; // Declare a flag variable

        if (n > m) { // Swap n and m if n is greater than m
            int temp = n;
            n = m;
            m = temp;
        }

        for (int i = 1; i <= m; i++) { // Iterate from 1 to m
            if (i * tc >= n && i * tc <= m) { // Check if the product of i and tc is between n and m
                System.out.println("OK"); // Print "OK" if the condition is met
                fl = 1; // Set the flag to true
                break; // Exit the loop
            }
        }

        if (fl == 0) {
            System.out.println("NG"); // Print "NG" if the flag is still false after the loop
        }

        scanner.close(); // Close the scanner
    }
} // End of the Main class
// <END-OF-CODE>
