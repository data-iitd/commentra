import java.util.Scanner;

public class Main {
    private static final long MOD = 1000000007;

    // Function to calculate x^n % MOD using bitwise operations
    private static long modPow(long x, long n) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) { // Check if the least significant bit is 1
                ans = ans * x % MOD; // Update ans if the bit is set
            }
            x = x * x % MOD; // Square x and take modulo MOD
            n >>= 1; // Shift n right by 1 bit (divide by 2)
        }
        return ans;
    }

    // Function to calculate combination C(n, r) % MOD
    private static long combS(long n, long r) {
        long tmpN = 1;
        long tmpD = 1;
        long ans = 0;
        for (int i = 1; i <= r; i++) {
            tmpN = (tmpN * (n + 1 - i)) % MOD; // Compute the numerator
            tmpD = (tmpD * i) % MOD; // Compute the denominator
            ans = tmpN * modPow(tmpD, MOD - 2) % MOD; // Compute the combination
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long ans = 1;

        ans = modPow(2, n); // Calculate 2^n % MOD
        ans--; // Subtract 1 from ans
        long tmpNd = combS(n, a); // Calculate C(n, a) % MOD
        ans = (ans - tmpNd + MOD) % MOD; // Subtract the combination from ans

        tmpNd = combS(n, b); // Calculate C(n, b) % MOD
        ans = (ans - tmpNd + MOD) % MOD; // Subtract the combination from ans

        System.out.println(ans); // Output the final result
        scanner.close();
    }
}

// <END-OF-CODE>
