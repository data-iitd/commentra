import java.util.Scanner;

public class Main {
    // Function to calculate the greatest common divisor (GCD)
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to calculate the least common multiple (LCM)
    public static int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }

    public static void main(String[] args) {
        final int MOD = (int) Math.pow(10, 9) + 7;
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        scanner.close();

        long _lcm = 1;
        for (int a : A) {
            _lcm = _lcm * a / gcd(Math.toIntExact(_lcm), a);
        }

        long ans = _lcm * sum(A) % MOD;
        for (int s : A) {
            ans *= modInverse(s, MOD);
            ans %= MOD;
        }

        System.out.println(ans % MOD);
    }

    // Function to calculate the sum of elements in an array
    public static int sum(int[] array) {
        int sum = 0;
        for (int value : array) {
            sum += value;
        }
        return sum;
    }

    // Function to calculate the modular inverse
    public static int modInverse(int a, int m) {
        int m0 = m, t, q;
        int x0 = 0, x1 = 1;

        if (m == 1) {
            return 0;
        }

        while (a > 1) {
            q = a / m;
            t = m;

            m = a % m;
            a = t;
            t = x0;

            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) {
            x1 += m0;
        }

        return x1;
    }
}
