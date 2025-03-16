

import java.io.*;
import java.util.*;

class atcoder_AGC028_B {
    static final int MOD = 100000007;  // Define the modulo constant
    static final int N = 1000000;  // Define a constant for the factorial table size
    static final int Nsq = 1000;  // Define a constant for the size of the factorial table

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());  // Read the size of the array
        String[] s = br.readLine().split(" ");  // Read the array elements
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(s[i]);
        }

        long[] fact = new long[Nsq];  // Initialize the factorial table
        fact[0] = 1;
        for (int n = 1; n < Nsq; n++) {
            fact[n] = fact[n - 1] * n % MOD;  // Compute the factorial table
        }

        long[] inv = new long[N];  // Compute the inverse factorial values
        for (int i = 0; i < N; i++) {
            inv[i] = pow(i + 1, MOD - 2, MOD);
        }
        for (int i = 1; i < N; i++) {
            inv[i] = (inv[i] + inv[i - 1]) % MOD;
        }

        long[] temp = new long[n];  // Compute the temporary value
        for (int i = 0; i < n; i++) {
            temp[i] = inv[i] + inv[n - 1 - i] - 1;
        }

        long ans = 0;  // Compute the final answer
        for (int i = 0; i < n; i++) {
            ans += a[i] * temp[i] % MOD;
        }
        ans %= MOD;

        ans *= fact[n];  // Multiply the final answer with the factorial of N
        ans %= MOD;

        System.out.println(ans);  // Print the final answer
    }

    static long pow(long a, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }
}

