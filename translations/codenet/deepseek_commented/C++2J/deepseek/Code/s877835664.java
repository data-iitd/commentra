import java.util.*;

public class Main {
    // Function to calculate the greatest common divisor (GCD)
    public static <T> T gcd(T a, T b) { return b != 0 ? gcd(b, a % b) : a; }

    // Function to calculate the least common multiple (LCM)
    public static <T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

    // Function to get the prime factors of a number
    public static <T> Map<T, T> getPrimeFactor(T n) {
        Map<T, T> res = new HashMap<>();
        for (T i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                res.put(i, res.getOrDefault(i, 0) + 1);
                n /= i;
            }
        }
        if (n != 1) res.put(n, res.getOrDefault(n, 0) + 1);
        return res;
    }

    // Function to check if a number is a prime number
    public static <T> boolean IsPrimeNumber(T num) {
        if (num <= 2) return true;
        else if (num % 2 == 0) return false;

        double sqrtNum = Math.sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    // Function to calculate the modular inverse of a number
    public static long modinv(long a, long m) {
        long b = m, u = 1, v = 0;
        while (b != 0) {
            long t = a / b;
            a -= t * b;
            long temp = a;
            a = b;
            b = temp;
            u -= t * v;
            temp = u;
            u = v;
            v = temp;
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();

        // Vector to store N+1 integers
        long[] A = new long[(int) (N + 1)];
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        // Variables to track the current position and the dictionary
        long cur = 1;
        long[] dic = new long[(int) (N + 1)];
        Arrays.fill(dic, -1);
        boolean flg = false;
        for (int i = 1; i <= K; i++) {
            if (dic[(int) cur] < 0 || flg) {
                dic[(int) cur] = i;
                cur = A[(int) cur];
            } else if (!flg) {
                long tmp = K - (dic[(int) cur] - 1);
                tmp %= i - dic[(int) cur];
                i = (int) (K - tmp);
                flg = true;
            }
        }

        // Output the final position
        System.out.println(cur);
    }
}
