import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        int N = scanner.nextInt();
        int mod = 998244353;
        int __N = 8000;
        List<Long> g1 = new ArrayList<>(Collections.nCopies(8001, 1L));
        List<Long> g2 = new ArrayList<>(Collections.nCopies(8001, 1L));
        List<Long> inverse = new ArrayList<>(Collections.nCopies(8001, 1L));

        for (int i = 2; i <= __N; i++) {
            g1.set(i, (g1.get(i - 1) * i) % mod);
            inverse.set(i, (inverse.get(mod % i) * (mod - mod / i)) % mod);
            g2.set(i, (g2.get(i - 1) * inverse.get(i)) % mod);
        }

        long cmb(int n, int r, int mod) {
            if (r < 0 || r > n) {
                return 0;
            }
            r = Math.min(r, n - r);
            return g1.get(n) * g2.get(r) % mod * g2.get(n - r) % mod;
        }

        long kumiawase(int p, int q) {
            return cmb(p + q - 1, q - 1, mod);
        }

        long solve(int n) {
            assert n <= K + 1;
            long ans = 0;
            int kumi = (n - 1) / 2;
            for (int p = 0; p <= kumi; p++) {
                if (p > N) {
                    break;
                }
                ans += Math.pow(2, p) * cmb(kumi, p, mod) % mod * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0 ? 1 : 0))) % mod;
                if (n % 2 == 0 && N - p - 1 >= 0) {
                    ans += Math.pow(2, p) * cmb(kumi, p, mod) % mod * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0 ? 1 : 0))) % mod;
                }
            }
            return ans % 998244353;
        }

        List<Long> ans = new ArrayList<>();
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
