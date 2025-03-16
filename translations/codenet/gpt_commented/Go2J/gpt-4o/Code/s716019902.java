import java.util.Scanner;

public class Main {
    // Define constants for modulo operation and factorial limit
    static final int MOD = 998244353;
    static final int FAC_NUM = 300001;

    public static void main(String[] args) {
        // Initialize a new scanner for reading input
        Scanner sc = new Scanner(System.in);
        // Read an integer N from input
        int N = sc.nextInt();
        int sum = 0;

        // Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
        for (int i = 1; i <= N; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                continue; // Skip numbers divisible by 3 or 5
            }
            sum += i; // Add the number to the sum
        }

        // Output the final sum
        System.out.println(sum);
    }

    // Function to calculate a^n under modulo
    static int pow(int a, int n) {
        int ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = (int) ((1L * ans * a) % MOD); // Multiply by a if n is odd
            }
            a = (int) ((1L * a * a) % MOD); // Square a
            n >>= 1; // Right shift n
        }
        return ans; // Return the result
    }

    // Function to calculate the greatest common divisor of a and b
    static int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a); // Ensure a is greater than b
        }
        while (b != 0) {
            int temp = b;
            b = a % b; // Apply Euclidean algorithm
            a = temp;
        }
        return a; // Return the GCD
    }

    // Function to return the minimum of two integers
    static int min(int a, int b) {
        return a < b ? a : b; // Return the smaller one
    }

    // Function to calculate n choose k using precomputed factorials
    static int combination(int n, int k, int[] fac, int[] ifac) {
        if (n < k || n < 0) {
            return 0; // Return 0 if invalid
        }
        if (k == 0) {
            return 1; // Return 1 if k is 0
        }
        // Calculate combination using factorials
        return (int) (((1L * ifac[k] * ifac[n - k] % MOD) * fac[n]) % MOD);
    }

    // Function to precompute factorials and their modular inverses
    static int[][] factorial() {
        int[] fac = new int[FAC_NUM]; // Create a slice for factorials
        int[] ifac = new int[FAC_NUM]; // Create a slice for inverse factorials
        fac[0] = 1;
        ifac[0] = 1;
        for (int i = 1; i < FAC_NUM; i++) {
            fac[i] = (int) ((1L * fac[i - 1] * i) % MOD); // Compute factorial
            ifac[i] = (int) ((1L * ifac[i - 1] * pow(i, MOD - 2)) % MOD); // Compute inverse factorial using Fermat's little theorem
        }
        return new int[][]{fac, ifac};
    }

    // Function to find the index of the first element in a sorted array that is not less than v
    static int lowerBound(int[] vs, int v) {
        int n = vs.length / 2; // Initialize mid index
        int m = vs.length; // Length of the array
        while (m != n) {
            if (vs[n] < v) {
                n = (m - n + 1) / 2 + n; // Move to the right half
            } else {
                m = n; // Move to the left half
                n = n / 2; // Update mid index
            }
        }
        return n; // Return the found index
    }

    // Function to create an array of integers initialized to a specific value
    static int[] intSlice(int n, int init) {
        int[] r = new int[n]; // Create an array of length n
        for (int i = 0; i < n; i++) {
            r[i] = init; // Initialize each element
        }
        return r; // Return the initialized array
    }
}

// <END-OF-CODE>
