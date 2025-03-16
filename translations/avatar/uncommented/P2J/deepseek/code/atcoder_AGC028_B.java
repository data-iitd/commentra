import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007;
    static final int N_SQ = 1000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        String[] A_str = scanner.nextLine().split(" ");
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(A_str[i]);
        }

        long[] fact = new long[N_SQ * N_SQ];
        fact[0] = 1;
        for (int n = 1; n < N_SQ; n++) {
            for (int m = 0; m < N_SQ; m++) {
                fact[n * N_SQ + m] = fact[n * N_SQ + (m - 1)];
                if (m > 0) {
                    fact[n * N_SQ + m] *= fact[(n - 1) * N_SQ + m];
                }
                fact[n * N_SQ + m] %= MOD;
            }
        }

        long[] inv = new long[N];
        inv[0] = 1;
        for (int i = 1; i < N; i++) {
            inv[i] = pow(i + 1, MOD - 2, MOD);
        }

        long[] cumSumInv = new long[N];
        cumSumInv[0] = inv[0];
        for (int i = 1; i < N; i++) {
            cumSumInv[i] = (cumSumInv[i - 1] + inv[i]) % MOD;
        }

        long temp = 0;
        for (int i = 0; i < N; i++) {
            temp = (temp + cumSumInv[i] + cumSumInv[N - 1 - i] - 1) % MOD;
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans = (ans + A[i] * temp) % MOD;
        }

        ans *= fact[N];
        ans %= MOD;

        System.out.println(ans);
    }

    static long pow(long base, int exp, int mod) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
}
