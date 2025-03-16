import java.util.*;

public class Main {
    // Function to compute the greatest common divisor (GCD) of two numbers
    public static <T> T gcd(T a, T b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Function to compute the least common multiple (LCM) of two numbers
    public static <T> T lcm(T a, T b) {
        return a / gcd(a, b) * b;
    }

    // Function to get the prime factorization of a number
    public static Map<Long, Long> getPrimeFactor(long n) {
        Map<Long, Long> res = new HashMap<>();
        // Iterate from 2 to the square root of n
        for (long i = 2; i * i <= n; ++i) {
            // While i divides n, store i in the result map
            while (n % i == 0) {
                res.put(i, res.getOrDefault(i, 0L) + 1);
                n /= i;
            }
        }
        // If n is still greater than 1, it is a prime factor
        if (n != 1) res.put(n, 1L);
        return res;
    }

    // Function to check if a number is prime
    public static boolean IsPrimeNumber(long num) {
        if (num <= 2) return true; // 0, 1, and 2 are considered prime
        else if (num % 2 == 0) return false; // Exclude even numbers

        double sqrtNum = Math.sqrt(num);
        // Check for factors from 3 to the square root of num
        for (long i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false; // Found a factor, not prime
            }
        }

        return true; // No factors found, num is prime
    }

    // Function to compute modular inverse using the Extended Euclidean Algorithm
    public static long modinv(long a, long m) {
        long b = m, u = 1, v = 0;
        // Loop until b becomes zero
        while (b != 0) {
            long t = a / b;
            a -= t * b;
            long temp = a;
            a = b;
            b = temp; // Swap a and b
            u -= t * v;
            temp = u;
            u = v;
            v = temp; // Update u and v
        }
        u %= m; // Ensure u is within the modulo
        if (u < 0) u += m; // Adjust if u is negative
        return u; // Return the modular inverse
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();

        long[] A = new long[(int) (N + 1)];
        // Input the elements into the array A
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        long cur = 1; // Initialize current position
        long[] dic = new long[(int) (N + 1)];
        Arrays.fill(dic, -1); // Dictionary to store the first occurrence of each index
        boolean flg = false; // Flag to indicate if we have entered a cycle

        // Process the sequence based on the value of K
        for (long i = 1; i <= K; i++) {
            // If current index has not been seen before or we are in a cycle
            if (dic[(int) cur] < 0 || flg) {
                dic[(int) cur] = i; // Record the current index
                cur = A[(int) cur]; // Move to the next index
            }
            // If we have seen this index before and are not in a cycle
            else if (!flg) {
                long tmp = K - (dic[(int) cur] - 1); // Calculate remaining steps
                tmp %= i - dic[(int) cur]; // Adjust steps based on the cycle length
                i = K - tmp; // Update i to skip to the end of the cycle
                flg = true; // Set the flag indicating we are in a cycle
            }
        }

        // Output the final position after K steps
        System.out.println(cur);
    }
}
