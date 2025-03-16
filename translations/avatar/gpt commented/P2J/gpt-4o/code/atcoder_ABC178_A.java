import java.util.Scanner;

public class Main {
    // Define a method to solve the problem for a given test case
    public static void solve(int tc, Scanner scanner) {
        // Read an integer from standard input
        int a = Integer.parseInt(scanner.nextLine().trim());
        
        // Print 1 if the integer is 0, otherwise print 0
        System.out.println(a == 0 ? 1 : 0);
    }

    public static void main(String[] args) {
        // Initialize the number of test cases
        int tcs = 1;
        // Start with the first test case
        int tc = 1;

        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);

        // Loop through each test case until the specified number of test cases is reached
        while (tc <= tcs) {
            // Call the solve method for the current test case
            solve(tc, scanner);
            // Increment the test case counter
            tc++;
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
