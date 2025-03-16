import java.util.Scanner;

public class Main {
    static long mod = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        long[] A = new long[(int) N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }

        // Solution
        long ans1 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) continue; // Skip if i is not less than j
                if (A[i] > A[j]) ans1++; // Increment ans1 if A[i] > A[j]
                ans1 %= mod; // Take modulo to prevent overflow
            }
        }

        // Count the frequency of each element in the array A
        long[] count = new long[2005];
        for (int i = 0; i < N; i++) {
            count[(int) (A[i] - 1)]++; // Store frequency of A[i]
        }

        long ans2 = 0;
        long remain = N;
        for (int i = 0; i < 2005; i++) {
            remain -= count[i]; // Reduce the remaining count
            ans2 += count[i] * remain; // Calculate the number of valid pairs
        }

        // Calculate the final answer
        long tmp = K * (K - 1) / 2; // Calculate K*(K-1)/2
        tmp %= mod; // Take modulo to prevent overflow
        tmp *= ans2; // Multiply with ans2
        tmp %= mod; // Take modulo to prevent overflow
        long ans = 0;
        ans += ans1 * K; // Add contribution from ans1
        ans %= mod; // Take modulo to prevent overflow
        ans += tmp; // Add contribution from tmp
        ans %= mod; // Take modulo to prevent overflow

        // Output the final answer
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
