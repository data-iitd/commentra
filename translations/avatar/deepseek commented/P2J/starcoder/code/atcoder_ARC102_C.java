import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int mod = 998244353;
        int[] g1 = new int[8000];
        int[] g2 = new int[8000];
        int[] inverse = new int[8000];
        g1[0] = 1;
        g2[0] = 1;
        inverse[0] = 1;
        g1[1] = 1;
        g2[1] = 1;
        inverse[1] = 1;
        for (int i = 2; i < 8000; i++) {
            g1[i] = (g1[i - 1] * i) % mod;
            inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
            g2[i] = (g2[i - 1] * inverse[i]) % mod;
        }
        int[] ans = new int[2 * K + 1];
        for (int i = 2; i <= 2 * K + 1; i++) {
            if (i <= K + 1) {
                ans[i - 1] = solve(i, K, N, mod, g1, g2, inverse);
            } else {
                ans[i - 1] = ans[2 * K - i];
            }
            System.out.println(ans[i - 1]);
        }
    }

    public static int solve(int n, int K, int N, int mod, int[] g1, int[] g2, int[] inverse) {
        int ans = 0;
        int kumi = (n - 1) / 2;
        for (int p = 0; p <= kumi; p++) {
            if (p > N) {
                break;
            }
            ans += (int) Math.pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
            if (n % 2 == 0 && N - p - 1 >= 0) {
                ans += (int) Math.pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
            }
        }
        return ans % mod;
    }

    public static int cmb(int n, int r, int mod) {
        if (r < 0 || r > n) {
            return 0;
        }
        r = Math.min(r, n - r);
        return g1[n] * g2[r] * g2[n - r] % mod;
    }

    public static int kumiawase(int p, int q) {
        return cmb(p + q - 1, q - 1, mod);
    }
}

