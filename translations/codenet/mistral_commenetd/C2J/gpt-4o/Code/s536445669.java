import java.util.Scanner;

public class Main {
    // The main function is the entry point of the program
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Declare two integer variables 'n' and 'k'
        int n, k;

        // Read two integers from the standard input using Scanner
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Check if 'n' is divisible by 'k'
        if (n % k == 0) {
            // If it is, print '0' to the standard output
            System.out.println("0");
        } else {
            // If it's not, print '1' to the standard output
            System.out.println("1");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
