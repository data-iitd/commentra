
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int mod = 998244353;
        int[] g1 = new int[8001];
        int[] g2 = new int[8001];
        int[] inverse = new int[8001];
        g1[0] = 1;
        g1[1] = 1;
        g2[0] = 1;
        g2[1] = 1;
        inverse[0] = 0;
        inverse[1] = 1;
        for (int i = 2; i <= 8000; i++) {
            g1[i] = (g1[i - 1] * i) % mod;
            inverse[i] = (-inverse[mod % i] * (mod / i)) % mod;
            g2[i] = (g2[i - 1] * inverse[i]) % mod;
        }
        long[] ans = new long[2 * K + 1];
        for (int i = 2; i <= 2 * K + 1; i++) {
            if (i <= K + 1) {
                long tmp = 0;
                int kumi = (i - 1) / 2;
                for (int p = kumi + 1; p >= 0; p--) {
                    if (p > N) {
                        break;
                    }
                    tmp += (long) (2 * Math.pow(2, p) * g1[kumi] * g2[p] * g2[kumi - p] % mod);
                    if (i % 2 == 0 && N - p - 1 >= 0) {
                        tmp += (long) (2 * Math.pow(2, p) * g1[kumi] * g2[p] * g2[kumi - p] % mod);
                    }
                }
                ans[i] = tmp;
                System.out.println(tmp);
            } else {
                System.out.println(ans[2 * K + 1 - i]);
            }
        }
    }
}

