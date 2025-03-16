import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        int N = scanner.nextInt();
        System.out.println(K + " " + N);  // Debug print function

        final int mod = 998244353;  // Modulo value
        final int __N = 8000;  // Constant value
        long[] g1 = new long[__N + 1];
        long[] g2 = new long[__N + 1];
        long[] inverse = new long[__N + 1];

        g1[0] = 1;
        g1[1] = 1;
        g2[0] = 1;
        g2[1] = 1;
        inverse[0] = 0;
        inverse[1] = 1;

        // Precompute factorials, inverses, and modular inverses up to __N
        for (int i = 2; i <= __N; i++) {
            g1[i] = (g1[i - 1] * i) % mod;
            inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
            g2[i] = (g2[i - 1] * inverse[i]) % mod;
        }

        // Combination function to calculate binomial coefficient modulo mod
        long cmb(int n, int r, int mod) {
            if (r < 0 || r > n) {
                return 0;
            }
            r = Math.min(r, n - r);
            return g1[n] * g2[r] * g2[n - r] % mod;
        }

        // Function to calculate kumiawase (combination with repetition) modulo mod
        long kumiawase(int p, int q) {
            return cmb(p + q - 1, q - 1, mod);
        }

        // Function to solve the problem for a given n
        long solve(int n) {
            assert n <= K + 1;
            long ans = 0;
            int kumi = (n - 1) / 2;
            for (int p = 0; p <= kumi; p++) {
                if (p > N) {
                    break;
                }
                ans += Math.pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0 ? 0 : 1)));
                if (n % 2 == 0 && N - p - 1 >= 0) {
                    ans += Math.pow(2, p) * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0 ? 0 : 1)));
                }
            }
            return ans % 998244353;
        }

        List<Long> ans = new ArrayList<>();  // List to store results
        for (int i = 2; i <= 2 * K; i++) {
            if (i <= K + 1) {
                long tmp = solve(i);
                ans.add(tmp);
                System.out.println(tmp);
            } else {
                System.out.println(ans.get(ans.size() - i + K));
            }
        }
    }
}
