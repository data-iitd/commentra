import java.util.Scanner;

public class Main {
    // Function to solve a single test case
    public static void solve(int tc, Scanner scanner) {
        // Read the next test case and store it in a variable 'a'
        int a = Integer.parseInt(scanner.nextLine().trim());

        // Print the solution for the current test case
        System.out.println(a == 0 ? 1 : 0);
    }

    public static void main(String[] args) {
        // Initialize the number of test cases
        int tcs = 1;
        int tc = 1;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Run the solution function for each test case
        while (tc <= tcs) {
            // Solve the current test case
            solve(tc, scanner);

            // Increment the test case counter
            tc++;
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
