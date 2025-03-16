import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // Solve the problem
        int ans1 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue; // Skip if i is not less than j
                if (A[i] > A[j]) ans1++; // Increment ans1 if A[i] > A[j]
                ans1 %= mod; // Take modulo to prevent overflow
            }
        }

        // Count the frequency of each element in the array A
        int[] count = new int[2005];
        for (int i = 0; i < N; i++) {
            count[A[i] - 1]++; // Store frequency of A[i]
        }

        int ans2 = 0;
        int remain = N;
        for (int i = 0; i < 2005; i++) {
            remain -= count[i]; // Reduce the remaining count
            ans2 += count[i] * remain; // Calculate the number of valid pairs
        }

        // Calculate the final answer
        int tmp = K * (K - 1);
        tmp /= 2; // Calculate K*(K-1)/2
        tmp %= mod; // Take modulo to prevent overflow
        tmp *= ans2; // Multiply with ans2
        tmp %= mod; // Take modulo to prevent overflow
        int ans = 0;
        ans += ans1 * K; // Add contribution from ans1
        ans %= mod; // Take modulo to prevent overflow
        ans += tmp; // Add contribution from tmp
        ans %= mod; // Take modulo to prevent overflow

        // Output the final answer
        System.out.println(ans);
    }
}

