import java.util.*;

public class Main {
    // Function to calculate the greatest common divisor (GCD)
    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Function to calculate the least common multiple (LCM)
    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    // Function to get the prime factors of a number
    public static Map<Long, Long> getPrimeFactor(long n) {
        Map<Long, Long> res = new HashMap<>();
        for (long i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                res.put(i, res.getOrDefault(i, 0L) + 1);
                n /= i;
            }
        }
        if (n != 1) res.put(n, 1L);
        return res;
    }

    // Function to check if a number is a prime number
    public static boolean isPrimeNumber(long num) {
        if (num <= 2) return true;
        else if (num % 2 == 0) return false;

        double sqrtNum = Math.sqrt(num);
        for (long i = 3; i <= sqrtNum; i += 2) {
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
            long temp = a; a = b; b = temp;
            u -= t * v; 
            temp = u; u = v; v = temp;
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
        for (long i = 1; i <= N; i++) {
            A[(int) i] = scanner.nextLong();
        }

        // Variables to track the current position and the dictionary
        long cur = 1;
        long[] dic = new long[(int) (N + 1)];
        Arrays.fill(dic, -1);
        boolean flg = false;

        for (long i = 1; i <= K; i++) {
            if (dic[(int) cur] < 0 || flg) {
                dic[(int) cur] = i;
                cur = A[(int) cur];
            } else if (!flg) {
                long tmp = K - (dic[(int) cur] - 1);
                tmp %= (i - dic[(int) cur]);
                i = K - tmp;
                flg = true;
            }
        }

        // Output the final position
        System.out.println(cur);
        scanner.close();
    }
}
// <END-OF-CODE>
