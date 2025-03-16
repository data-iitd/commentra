// Go: //go:generate echo "https://atcoder.jp/contests/dp/tasks/dp_a"
import java.util.Scanner;

public class Main {
    // Method to read an integer from input
    private static int readInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Method to read an array of integers from input
    private static int[] readIntArray(Scanner scanner, int length) {
        int[] array = new int[length];
        for (int i = 0; i < length; i++) {
            array[i] = readInt(scanner);
        }
        return array;
    }

    // Method to compute the absolute value of an integer
    private static int iabs(int x) {
        return x < 0 ? -x : x;
    }

    // Method to solve the problem using dynamic programming
    private static int solve(int n, int[] heights) {
        int[] t = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            t[i] = Integer.MAX_VALUE; // Initialize all costs to a large value
        }

        t[0] = 0; // The cost to reach the first height is zero
        for (int i = 1; i < n; i++) {
            // Calculate the cost to reach the current height from the previous height
            t[i] = Math.min(t[i], t[i - 1] + iabs(heights[i] - heights[i - 1]));
            // Calculate the cost to reach the current height from two heights back
            if (i > 1) {
                t[i] = Math.min(t[i], t[i - 2] + iabs(heights[i] - heights[i - 2]));
            }
        }

        return t[n - 1]; // Return the minimum cost to reach the last height
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize the scanner for standard input
        int n = readInt(scanner); // Read the number of heights
        int[] heights = readIntArray(scanner, n); // Read the heights into an array
        int ans = solve(n, heights); // Solve for the minimum cost
        System.out.println(ans); // Print the result
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
