public class Main {
    // Computes the greatest common divisor of two numbers x and y
    static long gcd(long x, long y) {
        long tmp = 0;
        if (x < y) {
            tmp = x;
            x = y;
            y = tmp;
        }
        while (y > 0) {
            long r = x % y;
            x = y;
            y = r;
        }
        return x;
    }

    // Computes the least common multiple of two numbers x and y
    static long lcm(long x, long y) {
        return x / gcd(x, y) * y;
    }

    // Computes the factorial of a number k modulo 10^9 + 7
    static long kaijo(long k) {
        long sum = 1;
        for (long i = 1; i <= k; ++i) {
            sum *= i;
            sum %= 1000000000 + 7;
        }
        return sum;
    }

    // Utility functions to find the maximum and minimum of two numbers
    static long lmax(long s, long t) {
        if (s > t) {
            return s;
        } else {
            return t;
        }
    }

    static long lmin(long s, long t) {
        if (s < t) {
            return s;
        } else {
            return t;
        }
    }

    // Main function
    public static void main(String[] args) {
        // Read two integers n and k
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        long sum = 0;

        // Iterate over possible values of b
        for (int b = 1; b <= n; b++) {
            // Calculate the count and remainder
            int cnt = (n + 1) / b;
            int md = (n + 1) % b;

            // Update the sum based on the conditions involving k
            sum += cnt * Math.max((b - k), 0) + Math.max((md - k), 0);

            // Adjust the sum if k is 0
            if (k == 0) sum--;
        }

        // Print the computed sum
        System.out.println(sum);
    }
}
