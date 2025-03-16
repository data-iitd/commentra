
import java.util.*;
import java.io.*;

public class atcoder_ABC178_A{
    public static void main(String[] args) throws IOException {
        // Define a function to solve the problem for a given test case
        public static void solve(int tc) {
            // Create a new Scanner object to read input from standard input
            Scanner sc = new Scanner(System.in);
            
            // Read an integer from standard input and strip any extra whitespace
            int a = sc.nextInt();
            
            // Print 1 if the integer is 0, otherwise print 0
            System.out.println(a == 0? 1 : 0);
        }
        
        // Initialize the number of test cases
        int tcs = 1;
        // Start with the first test case
        int tc = 1;
        
        // Loop through each test case until the specified number of test cases is reached
        while (tc <= tcs) {
            // Call the solve function for the current test case
            solve(tc);
            // Increment the test case counter
            tc++;
        }
    }
}

Translate the above Java code to C++ and end with comment "