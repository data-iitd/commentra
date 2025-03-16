
import java.io.PrintWriter; // Importing PrintWriter for output
import java.util.HashMap; // Importing HashMap for dynamic programming table
import java.util.Map; // Importing Map interface for HashMap
import java.util.Scanner; // Importing Scanner for input

public class Main {

  long MOD = 998244353L; // Modulus value for modular arithmetic

  long [ ] [ ] dp; // 2D dynamic programming table for storing intermediate results

  void solve(Scanner sc, PrintWriter pw) { // Function to solve the problem

    int A = sc.nextInt(); // Reading the first number A from input
    int B = sc.nextInt(); // Reading the second number B from input
    int C = sc.nextInt(); // Reading the third number C from input
    int D = sc.nextInt(); // Reading the fourth number D from input

    dp = new long[3001][3001]; // Initializing the dynamic programming table with zeros

    dp[A][B] = 1; // Setting the base case as dp[A][B] = 1

    for (int c = A; c <= C; c++) { // Iterating over all possible values of c from A to C
      for (int d = B; d <= D; d++) { // Iterating over all possible values of d from B to D
        if (c == A && d == B) { // Skipping the base case as it has already been calculated
          continue;
        }

        long ans = 0; // Initializing the answer as zero

        if (c > A) { // If c is greater than A
          long part = dp[c - 1][d]; // Calculating the sub-answer for the previous value of c and the same value of d
          ans = (part * d); // Multiplying the sub-answer with the current value of d
        }

        if (d > B) { // If d is greater than B
          long part = dp[c][d - 1]; // Calculating the sub-answer for the same value of c and the previous value of d
          ans = (ans + (part * c)); // Adding the sub-answer multiplied by the current value of c to the answer
        }

        if (c > A && d > B) { // If both c and d are greater than their respective initial values
          ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))); // Subtracting the answer for the previous values of c and d multiplied by their difference
        }

        dp[c][d] = (ans % MOD + MOD) % MOD; // Updating the answer for the current values of c and d
      }
    }

    pw.println(dp[C][D]); // Printing the final answer
  }

  public static void main(String[] args) { // Main function to run the program
    Scanner sc = new Scanner(System.in); // Creating a Scanner object for reading input
    PrintWriter pw = new PrintWriter(System.out); // Creating a PrintWriter object for writing output
    new Main().solve(sc, pw); // Calling the solve function to solve the problem
    pw.flush(); // Flushing the output buffer
    pw.close(); // Closing the output stream
    sc.close(); // Closing the input stream
  }
}

These comments should provide a clear understanding of the code for anyone who reads it.