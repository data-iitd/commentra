import java.util.Scanner;

public class Main {
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        long _lcm = 1;
        for (int a : A) {
            _lcm = _lcm * a / gcd(Math.toIntExact(_lcm), a);
        }

        long ans = _lcm * sum(A) % MOD;
        for (int s : A) {
            ans = ans * modInverse(s, MOD) % MOD;
        }

        System.out.println(ans % MOD);
    }

    private static final int MOD = (int) (1e9 + 7);

    public static int sum(int[] A) {
        int sum = 0;
        for (int a : A) {
            sum += a;
        }
        return sum;
    }

    public static int modInverse(int a, int m) {
        return pow(a, m - 2, m);
    }

    public static int pow(int base, int exp, int mod) {
        int result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
}
