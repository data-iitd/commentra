
import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        // Start a new thread to run the Main class
        new Thread(null, new Main(), "", 128 * 1024 * 1024).start();
    }

    public void run() {
        // Read the number of elements in the array from the standard input
        int n = sc.nextInt();

        // Allocate an integer array of size n
        int[] a = new int[n];

        // Read each element of the array from the standard input
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        // Initialize two long variables to store the minimum cost for the first and second subarrays
        long cost1 = 0;
        long cost2 = 0;

        // Initialize two integer variables to store the current elements in the first and second subarrays
        int current1 = 0;
        int current2 = 0;

        // Allocate two long arrays of size n to store the minimum cost for each subarray ending at the current index
        long[] dp1 = new long[n];
        long[] dp2 = new long[n];

        // Iterate through the array from the first index to the last index
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            // Calculate the cost of adding the current element to the first subarray
            cost1 += Math.abs(a[i] - current1);

            // Update the current element in the first subarray
            current1 = a[i];

            // Store the cost in the dp1 array
            dp1[i] = cost1;

            // Calculate the cost of adding the current element to the second subarray
            cost2 += Math.abs(a[j] - current2);

            // Update the current element in the second subarray
            current2 = a[j];

            // Store the cost in the dp2 array
            dp2[j] = cost2;
        }

        // Iterate through the array and print the minimum cost for each subarray
        for (int i = 0; i < n; i++) {
            // Special case for the first subarray
            if (i == 0) {
                // Print the minimum cost for the first subarray, which is the cost of the second subarray plus the absolute difference between the first and second elements
                System.out.println(dp2[i + 1] + Math.abs(a[1]));
            }

            // Special case for the last subarray
            else if (i == n - 1) {
                // Print the minimum cost for the last subarray, which is the cost of the previous subarray plus the absolute difference between the last and previous elements
                System.out.println(dp1[i - 1] + Math.abs(a[i - 1]));
            }

            // General case for the other subarrays
            else {
                // Print the minimum cost for the current subarray, which is the minimum cost of the previous and next subarrays plus the absolute difference between the previous and next elements
                System.out.println(dp1[i - 1] + dp2[i + 1] + Math.abs(a[i - 1] - a[i + 1]));
            }
        }
    }
}