import java.util.*;
import java.io.*;

public class Main {
    static final long MOD = 1000000007;
    static final int M = 1000000;
    static final int Nsq = 1000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        long[] A = Arrays.stream(br.readLine().trim().split(" "))
                         .mapToLong(Long::parseLong)
                         .toArray();

        long[][] fact = new long[Nsq][Nsq];
        fact[0][0] = 1;

        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[i][n] = (fact[i][n - 1] * (i + 1)) % MOD;
            }
        }

        for (int n = 1; n < Nsq; n++) {
            for (int i = 0; i < Nsq; i++) {
                fact[n][i] = (fact[n][i] * fact[n - 1][Nsq - 1]) % MOD;
            }
        }

        long[] flatFact = new long[Nsq * Nsq];
        for (int i = 0; i < Nsq; i++) {
            System.arraycopy(fact[i], 0, flatFact, i * Nsq, Nsq);
        }

        long[] inv = new long[N];
        for (int i = 0; i < N; i++) {
            inv[i] = pow(i + 1, MOD - 2, MOD);
        }

        long[] cumsum = new long[N];
        cumsum[0] = inv[0];
        for (int i = 1; i < N; i++) {
            cumsum[i] = (cumsum[i - 1] + inv[i]) % MOD;
        }

        long ans = 0;
        for (int j = 0; j < N; j++) {
            long temp = (cumsum[j] + cumsum[N - 1 - j] - 1 + MOD) % MOD;
            ans = (ans + (A[j] * temp) % MOD) % MOD;
        }

        ans = (ans * flatFact[N]) % MOD;
        System.out.println(ans);
    }

    static long pow(long base, long exp, long mod) {
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
//<END-OF-CODE>
