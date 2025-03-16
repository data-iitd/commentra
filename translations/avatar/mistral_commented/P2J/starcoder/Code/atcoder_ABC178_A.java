// Import necessary modules
import java.io.*;

// Function to solve a single test case
public static void solve(int a) {
    // Print the solution for the current test case
    System.out.println(1 if a == 0 else 0);
}

// Initialize the number of test cases and the test case counter
public static final int tcs = 1;
public static int tc = 1;

// Run the solution function for each test case
while (tc <= tcs) {
    // Read the next test case and store it in a variable 'a'
    int a = Integer.parseInt(System.console().readLine().strip());

    // Solve the current test case
    solve(a);

    // Increment the test case counter
    tc++;
}

