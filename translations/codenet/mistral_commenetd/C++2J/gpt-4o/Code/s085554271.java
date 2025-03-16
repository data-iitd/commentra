import java.util.Scanner;

public class Main {
    // Constants
    private static final long MOD = 1000000007; // Define constant for modulo arithmetic

    // Function to check if a number is prime
    public static boolean isPrime(int num) {
        if (num < 2) return false; // 2 is the smallest prime number
        else if (num == 2) return true; // 2 is a prime number
        else if (num % 2 == 0) return false; // Even numbers greater than 2 are not prime

        double sqrtNum = Math.sqrt(num); // Calculate square root of number
        for (int i = 3; i <= sqrtNum; i += 2) { // Iterate through odd numbers up to square root
            if (num % i == 0) { // If number is divisible by current odd number
                return false; // It's not a prime number
            }
        }

        // If number is not divisible by any odd number up to its square root, it's a prime number
        return true;
    }

    public static long gcd(long a, long b) {
        return b != 0 ? gcd(b, a % b) : a; // Recursive function to find greatest common divisor
    }

    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b; // Find least common multiple by multiplying greatest common divisor and smaller number
    }

    public static int max(int a, int b, int c) {
        return Math.max(Math.max(a, b), c); // Find maximum of three numbers
    }

    public static int min(int a, int b, int c) {
        return Math.min(Math.min(a, b), c); // Find minimum of three numbers
    }

    public static boolean isInteger(double num) {
        return Math.floor(num) == num; // Check if a number is an integer
    }

    public static long fact(int num) {
        if (num == 0) // Base case: factorial of 0 is 1
            return 1;
        else
            return num * fact(num - 1); // Recursive call to calculate factorial
    }

    public static long yakusu(int n) {
        int cnt = 0; // Initialize divisor count
        for (int i = 1; i * i <= n; i++) { // Iterate through divisors up to square root of n
            if (n % i == 0) { // If n is divisible by current divisor
                cnt++; // Increment divisor count
                if (i * i != n) cnt++; // If n has more than one divisor, increment count
            }
        }
        return cnt; // Return divisor count
    }

    public static long factMod(long n, long mod) {
        long f = 1; // Initialize factorial to 1
        for (long i = 2; i <= n; i++) f = f * (i % MOD) % MOD; // Calculate factorial modulo m
        return f; // Return the result
    }

    // Function to calculate x^n modulo m using repeated squaring method
    public static long modPow(long x, long n, long mod) {
        long res = 1; // Initialize result to 1
        while (n > 0) { // While n is not zero
            if ((n & 1) == 1) res = (res * x) % mod; // If n is odd, multiply x with result and reduce modulo m
            x = (x * x) % mod; // Square x and reduce modulo m
            n >>= 1; // Divide n by 2
        }
        return res; // Return the final result
    }

    // Function to calculate the number of combinations of n items taken r at a time modulo m
    public static long combinationMod(long n, long r, long mod) {
        if (r > n - r) r = n - r; // Adjust r if it's greater than the difference between n and r
        if (r == 0) return 1; // Base case: combination of 0 items is 1
        long a = 1; // Initialize first term
        for (long i = 0; i < r; i++) a = a * ((n - i) % MOD) % MOD; // Calculate first term
        long b = modPow(factMod((int) r, mod), mod - 2, mod); // Calculate second term
        return (a % MOD) * (b % MOD) % MOD; // Multiply terms and reduce modulo m
    }

    public static boolean isPalindrome(String s) {
        String t = s; // Create a copy of string s
        String reversed = new StringBuilder(s).reverse().toString(); // Reverse string s
        return s.equals(reversed); // Check if original string is equal to its reversed version
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long k = scanner.nextLong(); // Read input value for k
        long a = scanner.nextLong(); // Read input value for a
        long b = scanner.nextLong(); // Read input value for b

        // Check if there exists an integer between a and b that is divisible by k
        for (long i = a; i <= b; ++i) {
            if (i % k == 0) { // If current number is divisible by k
                System.out.println("OK"); // Print "OK" and exit the program
                return; // Exit the program with success status
            }
        }

        System.out.println("NG"); // If no number between a and b is divisible by k, print "NG"
    }
}
//<END-OF-CODE>
