import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int MOD = (int) (1e9 + 7);
    static final int M = (int) (1e6);
    static final int Nsq = 1000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String[] A_input = scanner.nextLine().split(" ");
        long[] A = Arrays.stream(A_input).mapToLong(Long::parseLong).toArray();

        long[] fact = new long[M];
        fact[0] = 1;
        for (int n = 1; n < M; n++) {
            fact[n] = fact[n - 1] * n % MOD;
        }

        long[] inv = new long[N];
        inv[0] = 1;
        for (int i = 1; i < N; i++) {
            inv[i] = pow(fact[i], MOD - 2);
        }

        long[] invCumSum = new long[N];
        invCumSum[0] = inv[0];
        for (int i = 1; i < N; i++) {
            invCumSum[i] = (invCumSum[i - 1] + inv[i]) % MOD;
        }

        long[] temp = new long[N];
        for (int i = 0; i < N; i++) {
            temp[i] = (invCumSum[i] + invCumSum[N - 1 - i] - 1 + MOD) % MOD;
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans = (ans + A[i] * temp[i] % MOD) % MOD;
        }

        ans = ans * fact[N] % MOD;
        System.out.println(ans);
    }

    static long pow(long base, int exp) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * base % MOD;
            }
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }
}
