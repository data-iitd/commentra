import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Input: Read the values of N and K
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Solution: Calculate the number of inversions in the array
        int ans1 = 0; // Initialize the count of inversions
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue; // Skip if i is greater than or equal to j
                if (A[i] > A[j]) ans1++; // Count inversion if A[i] > A[j]
            }
        }

        // Count occurrences of each element in the array
        int[] count = new int[2005]; // Initialize a count array to store frequencies
        for (int i = 0; i < N; i++) {
            count[A[i] - 1]++; // Increment the count for the corresponding value
        }

        // Calculate the second part of the answer based on the counts
        int ans2 = 0; // Initialize the second answer
        int remain = N; // Remaining elements to consider
        for (int i = 0; i < 2005; i++) { // Iterate through the count array
            remain -= count[i]; // Decrease the remaining count by the current count
            ans2 += count[i] * remain; // Calculate pairs of inversions
        }

        // Calculate the final answer based on ans1 and ans2
        int ans = 0; // Initialize the final answer
        int tmp = K * (K - 1); // Calculate the number of ways to choose 2 from K
        tmp /= 2; // Divide by 2 to get combinations
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

