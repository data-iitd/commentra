// Constants and package imports
import java.util.Scanner;

public class Main {
    // Constant for modulo
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        // Creating a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Reading the first two integers h and n
        int h = scanner.nextInt();
        int n = scanner.nextInt();

        // Initializing variable a to 0
        int a = 0;

        // Iterating through the array of size n and adding each integer to variable a
        for (int i = 0; i < n; i++) {
            a += scanner.nextInt();
        }

        // Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
        if (h > a) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
