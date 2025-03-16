import java.util.*;

public class Main {
    // Define aliases for common data types and containers
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    // Define helper functions for gcd and lcm

    static Map<Long, Long> getPrimeFactor(long n) {
        Map<Long, Long> res = new HashMap<>();
        // Initialize an empty map to store prime factors and their exponents

        for (long i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                res.put(i, res.getOrDefault(i, 0L) + 1);
                // If the number is divisible by 'i', add it to the map with its exponent incremented

                n /= i;
            }
        }
        if (n != 1) res.put(n, 1L);
        // If the number is not 1, add it to the map with exponent 1

        return res;
    }

    // Function to get prime factors of a number

    static boolean isPrimeNumber(long num) {
        if (num <= 2) return true;
        else if (num % 2 == 0) return false;

        double sqrtNum = Math.sqrt(num);
        // Check if the number is prime by checking divisibility up to its square root

        for (long i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    // Function to check if a number is prime

    static long modinv(long a, long m) {
        long b = m, u = 1, v = 0;
        // Extended Euclidean Algorithm to find modular multiplicative inverse

        while (b != 0) {
            long t = a / b;
            a -= t * b; 
            long temp = a; a = b; b = temp;
            u -= t * v; 
            temp = u; u = v; v = temp;
        }
        u %= m;
        // Make the result positive and less than 'm'

        if (u < 0) u += m;
        return u;
    }

    // Function to find modular multiplicative inverse

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();
        // Read input for 'N' and 'K'

        long[] A = new long[(int) N + 1];
        // Initialize an array 'A' of size 'N+1'

        for (long i = 1; i <= N; i++) {
            A[(int) i] = scanner.nextLong();
            // Read input for each element of the array 'A'
        }

        long cur = 1;
        // Initialize a variable 'cur' to keep track of the current position in the array

        long[] dic = new long[(int) N + 1];
        Arrays.fill(dic, -1);
        // Initialize an array 'dic' of size 'N+1' to store the distance from the start for each position

        boolean flg = false;
        // Initialize a boolean variable 'flg' to check if we need to reverse the direction of traversal

        for (long i = 1; i <= K; i++) {
            if (dic[(int) cur] < 0 || flg) {
                dic[(int) cur] = i;
                // If the distance from the start for the current position is not yet determined or we need to reverse the direction, update the distance

                cur = A[(int) cur];
                // Move to the next position
            } else if (!flg) {
                long tmp = K - (dic[(int) cur] - 1);
                tmp %= i - dic[(int) cur];
                // Calculate the number of steps we need to take to reach the position 'i' from the current position

                i = K - tmp;
                // Update 'i' to the position we need to reach

                flg = true;
            }
        }

        System.out.println(cur);
        // Print the final answer, which is the position of the last visited node
    }
}
// Main function to solve the problem
// <END-OF-CODE>
