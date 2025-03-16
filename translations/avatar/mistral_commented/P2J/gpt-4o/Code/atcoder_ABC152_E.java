import java.util.Scanner;

public class Main {
    // Function to calculate the greatest common divisor (GCD) of two numbers
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
        // Setting the value of MOD to 10^9 + 7
        final long MOD = 1000000007;

        // Reading the input N
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];

        // Storing the list A of N integers
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Initializing the variable _lcm to 1
        long _lcm = 1;

        // Iterating through each number a in the list A and updating the value of _lcm
        for (int a : A) {
            _lcm = lcm((int) _lcm, a);
        }

        // Calculating the answer ans
        long ans = _lcm;
        for (int s : A) {
            ans = (ans * modInverse(s, MOD)) % MOD;
        }

        // Printing the final answer
        System.out.println(ans);
    }

    // Function to calculate modular inverse using Fermat's Little Theorem
    public static long modInverse(int a, long mod) {
        return pow(a, mod - 2, mod);
    }

    // Function to calculate (base^exp) % mod
    public static long pow(int base, long exp, long mod) {
        long result = 1;
        base = base % (int) mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % (int) mod;
        }
        return result;
    }
}

// <END-OF-CODE>
