
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in); // create a Scanner object to read input from the console
        int numberOfTestCases = scanner.nextInt(); // read the number of test cases

        for (int testCase = 0; testCase < numberOfTestCases; testCase++) {
            int n = scanner.nextInt(); // read the size of the array
            int[][] arr = new int[n][3]; // create a 2D integer array of size n x 3

            for (int i = 0; i < n; i++) { // iterate through each row of the array
                for (int j = 0; j < 3; j++) { // iterate through each column of the array
                    arr[i][j] = scanner.nextInt(); // read an integer value and store it in the current cell of the array
                }
            }

            int answer = dpx(arr, n); // call the dpx function to find the answer
            System.out.println(answer); // print the answer
        }
    }

    // A recursive function to find the minimum difference between two elements in an array of size n
    static int min(int[] arr, int n) {
        if (n <= 1) { // base case: if the array size is 1 or 2, return 0
            return 0;
        }

        int op1 = Math.abs(arr[n - 1] - arr[n - 2]) + min(arr, n - 1); // recursive call with the subarray of size n-1
        int op2 = Math.abs(arr[n - 1] - arr[n - 3]) + min(arr, n - 2); // recursive call with the subarray of size n-2

        return Math.min(op1, op2); // return the minimum of op1 and op2
    }

    // A dynamic programming function to find the maximum sum of a subarray of size i+1 ending at index n-1
    static int dpc(int[][] arr, int i, int n, int row) {
        if (row == n) { // base case: if we have reached the last row, return 0
            return 0;
        }

        int j = 0, k = 0; // initialize j and k based on the current row i

        if (i == 1) {
            j = 0;
            k = 2;
        } else if (i == 0) {
            j = 1;
            k = 2;
        } else {
            j = 0;
            k = 1;
        }

        return arr[row][i] + Math.max(dpc(arr, j, n, row + 1), dpc(arr, k, n, row + 1)); // recursive call with the subarrays of size i+1 ending at j and k
    }

    // A dynamic programming function to find the maximum sum of a subarray of size n
    static int dpx(int[][] arr, int n) {
        int[][] dp = new int[n][3]; // create a 2D integer array of size n x 3 to store the maximum sum of subarrays of different sizes ending at each index

        dp[0][0] = arr[0][0]; // initialize the first cell of the array with the first element
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][2];

        for (int i = 1; i < n; i++) { // iterate through each index of the array
            for (int in = 0; in < 3; in++) { // iterate through each possible size of the subarray ending at the current index
                int j = 0, k = 0; // initialize j and k based on the current size in

                if (in == 1) {
                    j = 0;
                    k = 2;
                } else if (in == 0) {
                    j = 1;
                    k = 2;
                } else {
                    j = 0;
                    k = 1;
                }

                dp[i][in] = Math.max(dp[i - 1][k], dp[i - 1][j]) + arr[i][in]; // update the current cell based on the maximum sum of the subarrays of size in-1 ending at j and k
            }
        }

        return Math.max(dp[n - 1][0], Math.max(dp[n - 1][1], dp[n - 1][2])); // return the maximum sum of the subarrays of size 1, 2, and 3 ending at the last index
    }
}