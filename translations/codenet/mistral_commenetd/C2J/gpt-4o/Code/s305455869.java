import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a, b; // Declare two integer variables 'a' and 'b'
        int ans; // Declare an integer variable 'ans' to store the answer

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        a = scanner.nextInt(); // Read the first integer
        b = scanner.nextInt(); // Read the second integer

        ans = 0; // Initialize the answer variable 'ans' to zero

        // Check if 'a' is greater than or equal to 13
        if (a >= 13) {
            ans = b; // If 'a' is greater than or equal to 13, then the answer is 'b'
        }
        // Else if 'a' is greater than or equal to 6
        else if (a >= 6) {
            ans = b / 2; // If 'a' is greater than or equal to 6, then the answer is half of 'b'
        }

        System.out.println(ans); // Print the answer to the standard output

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
