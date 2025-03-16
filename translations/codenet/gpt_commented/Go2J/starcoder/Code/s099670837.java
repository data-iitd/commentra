import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the size of the array from standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize a 2D array to store the input values
        int[][] a = new int[2][n];

        // Loop to read the values into the 2D array
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        // Initialize a variable to store the answer
        int ans = 0;

        // Define a recursive function to find the maximum sum path
        // i: row index
        // j: column index
        // sum: current sum
        // a: 2D array
        // n: size of the array
        // ans: maximum sum path
        // arraySize: size of the 2D array
        // findAns(int i, int j, int sum)
        // {
        //     // Check if the current position is the bottom-right corner and if the current sum is greater than the recorded answer
        //     if (i == 1 && j == n-1 && sum+a[i][j] > ans) {
        //         // Update the answer with the new maximum sum
        //         ans = sum + a[i][j];
        //         return;
        //     }
        //     // If we are at the first row, move down to the next row
        //     if (i == 0) {
        //         findAns(i+1, j, sum+a[i][j]);
        //     }
        //     // If we can move right within the bounds of the array, do so
        //     if (j+1 < n) {
        //         findAns(i, j+1, sum+a[i][j]);
        //     }
        // }

        // Start the recursive function to find the maximum sum path from the top-left corner
        // findAns(0, 0, 0);

        // Print the final answer
        System.out.println(ans);
    }
}

