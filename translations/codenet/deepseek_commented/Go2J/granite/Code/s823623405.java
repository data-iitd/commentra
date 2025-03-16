
import java.util.Scanner;

public class s823623405{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt();
        }
        int[] ps = new int[1000001];
        for (int i = 0; i < n; i++) {
            int a = as[i];
            for (int j = 2; j * j <= a; j++) {
                while (a % j == 0) {
                    ps[j]++;
                    a /= j;
                }
            }
            if (a!= 1) {
                ps[a]++;
            }
        }
        int x = 1;
        for (int i = 2; i <= 1000000; i++) {
            for (int j = 0; j < ps[i]; j++) {
                x = mul(x, i);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = add(ans, div(x, as[i]));
        }
        System.out.println(ans);
    }

    static int max(int a, int b) {
        return a > b? a : b;
    }

    static int[] primeFactorize(int n) {
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

    static final int mod = 1000000007;

    static int pow(int n, int k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return pow(n, k - 1) * n % mod;
        } else {
            int t = pow(n, k / 2);
            return t * t % mod;
        }
    }

    static int add(int a, int b) {
        return (a + b) % mod;
    }

    static int sub(int a, int b) {
        return (a + mod - b) % mod;
    }

    static int mul(int a, int b) {
        return a % mod * b % mod % mod;
    }

    static int div(int a, int b) {
        return mul(a, pow(b, mod - 2));
    }
}

