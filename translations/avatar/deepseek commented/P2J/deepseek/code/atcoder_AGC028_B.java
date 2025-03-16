import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.stream.IntStream;
import java.util.stream.LongStream;

public class Main {
    static final int MOD = (int) (1e9 + 7);
    static final int Nsq = 1000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        long[] A = LongStream.of(input).mapToLong(Long::parseLong).toArray();

        int M = 1000000;
        long[] fact = new long[M];
        fact[0] = 1;

        for (int n = 1; n < Nsq; n++) {
            fact[n] = (fact[n - 1] * n) % MOD;
        }

        long[] inv = new long[N];
        inv[0] = 1;
        for (int i = 1; i < N; i++) {
            inv[i] = pow(i + 1, MOD - 2);
        }

        long[] invCumSum = new long[N];
        for (int i = 0; i < N; i++) {
            invCumSum[i] = inv[i];
            if (i > 0) {
                invCumSum[i] += invCumSum[i - 1];
            }
            invCumSum[i] %= MOD;
        }

        long temp = 0;
        for (int i = 0; i < N; i++) {
            temp += invCumSum[i] + invCumSum[N - 1 - i] - 1;
            temp %= MOD;
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += A[i] * temp % MOD;
            ans %= MOD;
        }

        ans *= fact[N];
        ans %= MOD;

        out.println(ans);
        out.flush();
    }

    static long pow(long base, int exp) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
}
