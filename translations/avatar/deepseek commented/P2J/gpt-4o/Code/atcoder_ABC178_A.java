import java.util.Scanner;

public class Main {
    // Define the solve method that takes a test case number as an argument
    public static void solve(int tc) {
        // Read an integer input from standard input
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        // Print 1 if the input is 0, otherwise print 0
        System.out.println(a == 0 ? 1 : 0);
    }

    public static void main(String[] args) {
        // Set the number of test cases to 1 and initialize the current test case number
        int tcs = 1;
        int tc = 1;

        // Enter a while loop that continues as long as the current test case number is less than or equal to the total number of test cases
        while (tc <= tcs) {
            // Call the solve method with the current test case number and increment the current test case number
            solve(tc);
            tc++;
        }
    }
}

// <END-OF-CODE>
