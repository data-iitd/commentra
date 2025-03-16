
import java.util.Scanner;

public class s823623405{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int[] p = new int[1000001];
        for (int i = 0; i < n; i++) {
            int x = a[i];
            for (int j = 2; j * j <= x; j++) {
                while (x % j == 0) {
                    p[j]++;
                    x /= j;
                }
            }
            if (x > 1) {
                p[x]++;
            }
        }

        int ans = 1;
        for (int i = 2; i <= 1000000; i++) {
            ans = mul(ans, pow(i, p[i]));
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = add(sum, div(ans, a[i]));
        }
        System.out.println(sum);
    }

    private static int max(int a, int b) {
        return a > b? a : b;
    }

    private static int[] primeFactorize(int n) {
        int[] res = new int[1000001];
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                res[i]++;
            }
        }
        if (n!= 1) {
            res[n]++;
        }
        return res;
    }

    private static final int mod = 1000000007;

    private static int pow(int n, int k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return pow(n, k - 1) * n % mod;
        } else {
            int t = pow(n, k / 2);
            return t * t % mod;
        }
    }

    private static int add(int a, int b) {
        return (a + b) % mod;
    }

    private static int sub(int a, int b) {
        return (a + mod - b) % mod;
    }

    private static int mul(int a, int b) {
        return a % mod * b % mod % mod;
    }

    private static int div(int a, int b) {
        return mul(a, pow(b, mod - 2));
    }
}
