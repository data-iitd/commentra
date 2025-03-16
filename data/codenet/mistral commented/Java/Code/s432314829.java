import java.util.Scanner; // Importing the Scanner class for reading input from the console

public class Main { // Defining the main class named Main
    public static void main(String[] args) { // Defining the main method that is the entry point of the program
        Scanner stdIn = new Scanner(System.in); // Creating a new Scanner object to read input from the console

        int n = stdIn.nextInt(); // Reading the first integer value from the console and storing it in the variable n
        int m = stdIn.nextInt(); // Reading the second integer value from the console and storing it in the variable m

        int dp[] = new int[n + 2]; // Creating an array of size n+2 and initializing it with zeros
        dp[n + 1] = 0; // Initializing the last index of the array with zero
        dp[n] = 1; // Initializing the index n with one

        for (int i = 0; i < m; i++) { // Starting a for loop that runs m times
            dp[stdIn.nextInt()] = -1; // Reading an integer value from the console and setting the corresponding index in the array dp to -1
        }

        for (int i = n - 1; i >= 0; i--) { // Starting a for loop that runs from n-1 to 0
            if (dp[i] == -1) { // Checking if the index i in the array dp is set to -1
                dp[i] = 0; // If yes, setting it to zero
            } else { // If not
                dp[i] = (dp[i + 1] + dp[i + 2]) % 1000000007; // Calculating the value of dp[i] as the sum of dp[i+1] and dp[i+2], and taking the modulo with 1000000007 to keep the result within the range
            }
        }

        System.out.println(dp[0]); // Printing the value of dp[0] to the console
    }
}
