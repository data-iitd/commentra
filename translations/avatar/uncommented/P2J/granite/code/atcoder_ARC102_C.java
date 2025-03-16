
import java.util.*;
import java.io.*;

class atcoder_ARC102_C {
    static int K, N;
    static long mod = 998244353;
    static long[] g1, g2, inverse;
    static {
        g1 = new long[8001];
        g2 = new long[8001];
        inverse = new long[8001];
        g1[0] = g2[0] = 1;
        inverse[1] = 1;
        for (int i = 1; i < 8001; i++) {
            g1[i] = (g1[i - 1] * i) % mod;
            inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
            g2[i] = (g2[i - 1] * inverse[i]) % mod;
        }
    }
    static long cmb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = Math.min(r, n - r);
        return g1[n] * g2[r] * g2[n - r] % mod;
    }
    static long kumiawase(int p, int q) {
        return cmb(p + q - 1, q - 1);
    }
    static long solve(int n) {
        assert n <= K + 1;
        long ans = 0;
        int kumi = (n - 1) / 2;
        for (int p = 0; p <= kumi; p++) {
            if (p > N) break;
            ans += (long)Math.pow(2, p) * cmb(kumi, p) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0? 1 : 0))) % mod;
            if (n % 2 == 0 && N - p - 1 >= 0) {
                ans += (long)Math.pow(2, p) * cmb(kumi, p) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0? 1 : 0))) % mod;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        N = sc.nextInt();
        List<Long> ans = new ArrayList<>();
        for (int i = 2; i <= 2 * K; i++) {
            if (i <= K + 1) {
                long tmp = solve(i) % mod;
                ans.add(tmp);
                System.out.println(tmp);
            } else {
                System.out.println(ans.get(i - K - 2));
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "