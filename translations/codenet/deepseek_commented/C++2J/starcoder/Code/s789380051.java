import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long a = in.nextLong();
        long b = in.nextLong();
        long ans = 1;

        ans = (long) Math.pow(2, n); // Calculate 2^n % MOD
        ans--; // Subtract 1 from ans
        long tmp_nd = comb_s(n, a); // Calculate C(n, a) % MOD
        ans = (ans - tmp_nd) % MOD; // Subtract the combination from ans
        while (ans < 0) { // Handle negative results
            ans += MOD;
        }

        tmp_nd = comb_s(n, b); // Calculate C(n, b) % MOD
        ans = (ans - tmp_nd) % MOD; // Subtract the combination from ans
        while (ans < 0) { // Handle negative results
            ans += MOD;
        }

        System.out.println(ans); // Output the final result
    }

    // Function to calculate x^n % MOD using bitwise operations
    static long mod_pow(long x, long n) {
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
    static long comb_s(long n, long r) {
        long tmp_n = 1;
        long tmp_d = 1;
        long ans;
        for (int i = 1; i <= r; i++) {
            tmp_n = (tmp_n * (n + 1 - i)) % MOD; // Compute the numerator
            tmp_d = (tmp_d * i) % MOD; // Compute the denominator
            ans = tmp_n * mod_pow(tmp_d, MOD - 2); // Compute the combination
        }
        return ans;
    }
}

