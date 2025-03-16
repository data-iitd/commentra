
import java.io.*;
import java.util.*;

class atcoder_ARC102_C {
    static long mod = 998244353;
    static long[] fact, factInv, inv;

    static void init() {
        fact = new long[8001];
        factInv = new long[8001];
        inv = new long[8001];
        fact[0] = fact[1] = 1;
        factInv[0] = factInv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < 8001; i++) {
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            factInv[i] = factInv[i - 1] * inv[i] % mod;
        }
    }

    static long cmb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = Math.min(r, n - r);
        return fact[n] * factInv[r] % mod * factInv[n - r] % mod;
    }

    static long kumiawase(int p, int q) {
        return cmb(p + q - 1, q - 1);
    }

    static long solve(int n) {
        int kumi = (n - 1) / 2;
        long ans = 0;
        for (int p = 0; p <= kumi; p++) {
            if (p > N) break;
            ans += (long) Math.pow(2, p) * cmb(kumi, p) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0? 1 : 0))) % mod;
            if (n % 2 == 0 && N - p - 1 >= 0) {
                ans += (long) Math.pow(2, p) * cmb(kumi, p) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0? 1 : 0))) % mod;
            }
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int K = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);
        init();
        List<Long> ans = new ArrayList<>();
        for (int i = 2; i <= 2 * K; i++) {
            if (i <= K + 1) {
                long tmp = solve(i);
                ans.add(tmp % mod);
                System.out.println(tmp);
            } else {
                System.out.println(ans.get(K + 1 - i));
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "