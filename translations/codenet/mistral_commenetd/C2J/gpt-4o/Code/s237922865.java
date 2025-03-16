import java.util.Scanner;

public class Main {
    // Main function starts here
    public static void main(String[] args) {
        // Declare and initialize variables
        Scanner scanner = new Scanner(System.in);
        int n;

        // Read an integer value from the user
        System.out.print("Enter the number of integers: ");
        n = scanner.nextInt();

        int cnt4 = 0, cnt2 = 0; // Initialize counters for 4's and 2's multiples

        // Iterate through each integer input
        for (int i = 0; i < n; i++) {
            int wk; // Declare a variable to store the current integer input

            // Read an integer value from the user
            System.out.print("Enter an integer: ");
            wk = scanner.nextInt();

            // Check if the current integer is a multiple of 4
            if (wk % 4 == 0) {
                cnt4++; // Increment the counter for 4's multiples
            }
            // Check if the current integer is a multiple of 2
            else if (wk % 2 == 0) {
                cnt2++; // Increment the counter for 2's multiples
            }
        }

        // Check the condition to determine the output
        if (cnt4 + cnt2 / 2 >= n / 2) {
            System.out.println("Yes"); // Output "Yes" if the condition is true
        } else {
            System.out.println("No"); // Output "No" if the condition is false
        }

        // Close the scanner
        scanner.close();
        // Main function ends here
    }
}
// <END-OF-CODE>
