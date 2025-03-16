
import java.util.*;
import java.io.*;

class s166776347 {
    public static void main(String[] args) {
        // Input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Number of elements in array A
        int K = sc.nextInt(); // Value of K
        int[] A = new int[N]; // Array to store input elements
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt(); // Read elements of array A from standard input
        }

        // Solution
        long ans1 = 0; // Initialize answer for the first part
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue; // Skip if current index is greater than or equal to the index of the inner loop
                if (A[i] > A[j]) ans1++; // Increment answer if the current element is greater than the inner element
                ans1 %= 100000007; // Update answer modulo 100000007 to avoid overflow
            }
        }

        int[] count = new int[2005]; // Initialize an array to store the count of each unique element in array A
        for (int i = 0; i < N; i++) {
            count[A[i] - 1]++; // Increment the count of the current element in the count array
        }

        long ans2 = 0; // Initialize answer for the second part
        long remain = N; // Initialize the remaining number of elements to be paired
        for (int i = 0; i < 2005; i++) {
            remain -= count[i]; // Decrement the remaining number of elements to be paired for the current unique element
            ans2 += count[i] * remain; // Calculate the contribution of the current unique element to the answer
        }

        long ans = 0; // Initialize the final answer
        long tmp = (long) K * (K - 1) / 2; // Calculate (K*(K-1)) modulo 100000007
        tmp %= 100000007; // Update the temporary variable modulo 100000007
        tmp *= ans2; // Multiply the temporary variable with the answer for the second part
        tmp %= 100000007; // Update the temporary variable modulo 100000007
        ans += ans1 * K; // Add the answer for the first part multiplied by K to the final answer
        ans %= 100000007; // Update the final answer modulo 100000007
        ans += tmp; // Add the temporary variable to the final answer
        ans %= 100000007; // Update the final answer modulo 100000007

        // Output
        System.out.println(ans); // Print the final answer
    }
}

