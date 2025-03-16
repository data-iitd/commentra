import java.util.Scanner;

public class Main {
    // Function to calculate the greatest common divisor (GCD)
    public static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to calculate the least common multiple (LCM)
    public static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }

    public static void main(String[] args) {
        final long MOD = 1000000007;  // Define a constant MOD for modular arithmetic
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();  // Read the number of elements from user input
        long[] A = new long[N];  // Create an array to store the integers
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();  // Read each integer into the array
        }

        long _lcm = 1;  // Initialize the variable to store the LCM of the list
        for (long a : A) {
            // Update the LCM by calculating the LCM of the current LCM and the next element
            _lcm = lcm(_lcm, a);
        }

        // Calculate the final answer using the LCM and the modular inverses of the elements in A
        long ans = _lcm;  // Start with the LCM
        for (long s : A) {
            ans = (ans * modInverse(s, MOD)) % MOD;  // Multiply by the modular inverse of each element
        }

        // Print the result, ensuring it is within the bounds of MOD
        System.out.println(ans % MOD);
    }

    // Function to calculate modular inverse using Fermat's Little Theorem
    public static long modInverse(long a, long mod) {
        return pow(a, mod - 2, mod);
    }

    // Function to perform modular exponentiation
    public static long pow(long base, long exp, long mod) {
        long result = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {  // If exp is odd
                result = (result * base) % mod;
            }
            exp >>= 1;  // Divide exp by 2
            base = (base * base) % mod;  // Square the base
        }
        return result;
    }
}
// <END-OF-CODE>
