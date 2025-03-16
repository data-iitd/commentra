import java.util.Scanner;

public class Main {
    static final long MOD = 1000000007;

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
                if (i >= j) continue;
                if (A[i] > A[j]) ans1++;
                ans1 %= MOD;
            }
        }

        long[] count = new long[2005];
        for (int i = 0; i < N; i++) {
            count[(int) (A[i] - 1)]++;
        }

        long ans2 = 0;
        long remain = N;
        for (int i = 0; i < 2005; i++) {
            remain -= count[i];
            ans2 += count[i] * remain;
        }

        long ans = 0;
        long tmp = K * (K - 1) / 2;
        tmp %= MOD;
        tmp *= ans2;
        tmp %= MOD;
        ans += ans1 * K;
        ans %= MOD;
        ans += tmp;
        ans %= MOD;

        // Output
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
