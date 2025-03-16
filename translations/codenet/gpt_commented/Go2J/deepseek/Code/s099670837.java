import java.util.Scanner;

public class Main {
    // Declare global variables for the size of the array and the answer
    static int n, ans;

    // Define a constant for the size of the array
    static final int ARRAY_SIZE = 101;

    // Initialize a 2D array to store the input values
    static int[][] a = new int[2][ARRAY_SIZE];

    // Recursive function to find the maximum sum path
    static void findAns(int i, int j, int sum) {
        // Check if the current position is the bottom-right corner and if the current sum is greater than the recorded answer
        if (i == 1 && j == n - 1 && sum + a[i][j] > ans) {
            // Update the answer with the new maximum sum
            ans = sum + a[i][j];
            return;
        }
        // If we are at the first row, move down to the next row
        if (i == 0) {
            findAns(i + 1, j, sum + a[i][j]);
        }
        // If we can move right within the bounds of the array, do so
        if (j + 1 < n) {
            findAns(i, j + 1, sum + a[i][j]);
        }
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Read the size of the array from standard input
        n = scanner.nextInt();

        // Loop to read the values into the 2D array
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt();
            }
        }
        // Start the recursive function to find the maximum sum path from the top-left corner
        findAns(0, 0, 0);
        // Print the final answer
        System.out.println(ans);
    }
}
