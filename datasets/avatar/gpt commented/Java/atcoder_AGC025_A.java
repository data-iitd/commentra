import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    
    // Method to calculate the sum of the digits of an integer 'a'
    public static int sum(int a) {
        int ans = 0; // Initialize the sum to 0
        // Loop until 'a' is less than 10
        while (a >= 10) {
            ans += a % 10; // Add the last digit of 'a' to 'ans'
            a /= 10; // Remove the last digit from 'a'
        }
        ans += a; // Add the remaining digit (which is less than 10) to 'ans'
        return ans; // Return the total sum of digits
    }

    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in); // Create a Scanner object for input
        int N = stdIn.nextInt(); // Read an integer input from the user
        int n = 0; // Variable to hold half of N or adjusted value

        // Determine the value of n based on whether N is even or odd
        if (N % 2 == 0) {
            n = N / 2; // If N is even, set n to half of N
        } else {
            n = (N + 1) / 2; // If N is odd, set n to the ceiling of half of N
        }

        // Initialize ans with the sum of digits of 1 and N-1
        int ans = sum(1) + sum(N - 1);

        // Loop through all values from 1 to n
        for (int A = 1; A <= n; A++) {
            // Check if the sum of digits of A and N-A is less than the current ans
            if (sum(A) + sum(N - A) < ans) {
                ans = sum(A) + sum(N - A); // Update ans with the new minimum sum
            }
        }

        // Output the minimum sum of digits found
        System.out.println(ans);
    }
}
