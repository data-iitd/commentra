
import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC150_E{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();
        }
        Arrays.sort(c);
        int mod = (int) 1e9 + 7;
        long b = pow(2, 2 * n - 2, mod);
        long a = 2 * b % mod;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c[i] * (a + i * b) % mod;
            ans %= mod;
        }
        System.out.println(ans);
    }

    private static long pow(long a, long n, int mod) {
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

