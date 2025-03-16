
import java.util.*;
import java.io.*;

class s166776347 {
    static long mod = 100000007; // Define modulus value for calculations

    public static void main(String[] args) throws Exception {
        // Input: Read the values of N and K
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);
        int[] A = new int[N];
        String[] input2 = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(input2[i]);
        }

        // Solution: Calculate the number of inversions in the array
        long ans1 = 0; // Initialize the count of inversions
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue; // Skip if i is greater than or equal to j
                if (A[i] > A[j]) ans1++; // Count inversion if A[i] > A[j]
                ans1 %= mod; // Take modulo to prevent overflow
            }
        }

        // Count occurrences of each element in the array
        int[] count = new int[2005]; // Initialize a count array to store frequencies
        for (int i = 0; i < N; i++) {
            count[A[i] - 1]++; // Increment the count for the corresponding value
        }

        // Calculate the second part of the answer based on the counts
        long ans2 = 0; // Initialize the second answer
        long remain = N; // Remaining elements to consider
        for (int i = 0; i < 2005; i++) { // Iterate through the count array
            remain -= count[i]; // Decrease the remaining count by the current count
            ans2 += count[i] * remain; // Calculate pairs of inversions
        }

        // Calculate the final answer based on ans1 and ans2
        long ans = 0; // Initialize the final answer
        long tmp = (long) K * (K - 1) / 2; // Calculate the number of ways to choose 2 from K
        tmp %= mod; // Take modulo
        tmp *= ans2; // Multiply by the second answer
        tmp %= mod; // Take modulo again
        ans += ans1 * K; // Add the contribution from ans1
        ans %= mod; // Take modulo
        ans += tmp; // Add the contribution from tmp
        ans %= mod; // Take modulo

        // Output: Print the final answer
        System.out.println(ans); // Output the result
    }
}

