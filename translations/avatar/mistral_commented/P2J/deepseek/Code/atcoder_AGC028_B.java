import java.util.*;

public class Main {
    static final int MOD = (int) (1e9 + 7);
    static final int M = (int) (1e6);
    static final int Nsq = (int) (1e3);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());

        String[] input = scanner.nextLine().split(" ");
        long[] A = Arrays.stream(input).mapToLong(Long::parseLong).toArray();

        long[][] fact = new long[Nsq][Nsq];
        fact[0][0] = 1;

        for (int n = 1; n < Nsq; n++) {
            for (int m = 0; m < Nsq; m++) {
                fact[n][m] = fact[n - 1][m] * (n + 1) % MOD;
            }
        }

        for (int n = 1; n < Nsq; n++) {
            for (int m = 0; m < Nsq; m++) {
                fact[n][m] = fact[n][m] * fact[n - 1][Nsq - 1] % MOD;
            }
        }

        long[] factArray = new long[Nsq * Nsq];
        int index = 0;
        for (int n = 0; n < Nsq; n++) {
            for (int m = 0; m < Nsq; m++) {
                factArray[index++] = fact[n][m];
            }
        }

        long[] j = new long[N];
        for (int i = 0; i < N; i++) {
            j[i] = i;
        }

        long[] inv = new long[N];
        inv[0] = 1;
        for (int i = 1; i < N; i++) {
            inv[i] = pow(i + 1, MOD - 2, MOD);
        }

        long[] invCumSum = new long[N];
        invCumSum[0] = inv[0];
        for (int i = 1; i < N; i++) {
            invCumSum[i] = (invCumSum[i - 1] + inv[i]) % MOD;
        }

        long[] temp = new long[N];
        for (int i = 0; i < N; i++) {
            temp[i] = (invCumSum[i] + invCumSum[N - 1 - i] - 1) % MOD;
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans = (ans + A[i] * temp[i] % MOD) % MOD;
        }

        ans = ans * factArray[N] % MOD;

        System.out.println(ans);
    }

    static long pow(long base, long exp, long mod) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * base % mod;
            }
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
}
