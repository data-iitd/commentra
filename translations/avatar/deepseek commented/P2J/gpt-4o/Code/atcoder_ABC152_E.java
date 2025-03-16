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

    // Function to calculate the least common multiple (LCM) of two numbers
    public static long lcm(int a, int b) {
        return (long) a * b / gcd(a, b);
    }

    public static void main(String[] args) {
        final int MOD = 1000000007;  // Define a constant MOD for modulo operations
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();  // Read the number of elements in the list A
        int[] A = new int[N];  // Initialize the array A
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();  // Read the list A as integers
        }

        long _lcm = 1;  // Initialize _lcm to 1
        for (int a : A) {
            _lcm = lcm((int) _lcm, a);  // Update _lcm to be the LCM of _lcm and the current element
        }

        // Calculate ans as _lcm multiplied by the sum of modular inverses of each element in A modulo MOD
        long ans = _lcm;  // Start with _lcm
        for (int s : A) {
            ans = (ans + modInverse(s, MOD)) % MOD;  // Add the modular inverse of each element
        }
        ans = (ans * _lcm) % MOD;  // Multiply by _lcm

        System.out.println(ans);  // Print the result
        scanner.close();
    }

    // Function to calculate modular inverse using Fermat's Little Theorem
    public static long modInverse(int a, int mod) {
        return pow(a, mod - 2, mod);
    }

    // Function to calculate (base^exp) % mod
    public static long pow(int base, int exp, int mod) {
        long result = 1;
        long b = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return result;
    }
}
// <END-OF-CODE>
