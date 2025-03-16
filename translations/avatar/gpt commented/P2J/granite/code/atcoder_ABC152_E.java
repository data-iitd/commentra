
import java.util.*;

class atcoder_ABC152_E {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int MOD = 100000007;  // Define a constant MOD for modular arithmetic
        int N = sc.nextInt();  // Read the number of elements from user input
        long[] A = new long[N];  // Create an array to store the input elements
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();  // Read the input elements and store them in the array
        }

        long lcm = 1;  // Initialize the variable to store the LCM of the list
        for (int i = 0; i < N; i++) {
            // Update the LCM by calculating the LCM of the current LCM and the next element
            lcm = lcm * A[i] / gcd(lcm, A[i]);
        }

        long ans = lcm;  // Initialize the variable to store the final answer
        for (int i = 0; i < N; i++) {
            // Update the answer by multiplying it with the modular inverse of the current element
            ans = ans * modinv(A[i], MOD) % MOD;
        }

        // Print the result, ensuring it is within the bounds of MOD
        System.out.println(ans % MOD);
    }

    // Function to calculate the greatest common divisor (GCD) of two numbers
    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    // Function to calculate the modular inverse of a number
    public static long modinv(long a, long m) {
        long b = m, u = 1, v = 0;
        while (b > 0) {
            long t = a / b;
            a -= t * b;
            long x = a;
            a = b;
            b = x;
            u -= t * v;
            long y = u;
            u = v;
            v = y;
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }
}

Translate the above Java code to C++ and end with comment "