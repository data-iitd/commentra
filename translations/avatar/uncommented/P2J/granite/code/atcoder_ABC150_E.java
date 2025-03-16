
import java.util.*;
import java.io.*;

class atcoder_ABC150_E {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] c_str = br.readLine().split(" ");
        long[] c = new long[n];
        for (int i = 0; i < n; i++) {
            c[i] = Long.parseLong(c_str[i]);
        }
        Arrays.sort(c);
        long mod = 100000007;
        long b = pow(2, 2 * n - 2, mod);
        long a = 2 * b % mod;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c[i] * (a + i * b) % mod;
            ans %= mod;
        }
        System.out.println(ans);
    }

    static long pow(long a, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            n /= 2;
        }
        return res;
    }
}
