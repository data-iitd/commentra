
import java.util.*;
import java.io.*;

class s789380051 {
    static long MOD = 1000000007L; // Define a constant for modulo operation

    // Function to compute (x^n) % MOD using modular exponentiation
    static long mod_pow(long x, long n){
        long ans = 1; // Initialize result
        while(n > 0){ // Loop until n becomes 0
            if((n & 1) == 1){ // If n is odd
                ans = ans * x % MOD; // Multiply ans by x and take modulo
            }
            x = x * x % MOD; // Square x and take modulo
            n >>= 1; // Divide n by 2
        }
        return ans; // Return the result
    }

    // Function to compute combination C(n, r) % MOD using modular arithmetic
    static long comb_s(long n, long r){
        long tmp_n = 1; // Temporary variable for numerator
        long tmp_d = 1; // Temporary variable for denominator
        long ans; // Variable to store the final answer
        for(int i = 1; i <= r; i++){ // Loop to calculate numerator and denominator
            tmp_n = (tmp_n * (n + 1 - i)) % MOD; // Calculate numerator
            tmp_d = (tmp_d * i) % MOD; // Calculate denominator
            ans = tmp_n * mod_pow(tmp_d, MOD - 2); // Calculate combination using modular inverse
        }

        return ans; // Return the combination result
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" "); // Read input as a string array
        long n = Long.parseLong(input[0]); // Parse the first input as long
        long a = Long.parseLong(input[1]); // Parse the second input as long
        long b = Long.parseLong(input[2]); // Parse the third input as long
        long ans = 1; // Initialize answer variable

        // Calculate 2^n - 1 (total subsets excluding the empty set)
        ans = mod_pow(2, n);
        ans--;

        long tmp_nd; // Temporary variable to store combinations

        // Calculate C(n, a) and subtract from ans
        tmp_nd = comb_s(n, a);
        ans = (ans - tmp_nd) % MOD; // Subtract combinations of size a
        while(ans < 0){ // Ensure ans is non-negative
            ans += MOD;
        }
        //System.out.println(ans + " " + tmp_ans); // Uncomment for debugging

        // Calculate C(n, b) and subtract from ans
        tmp_nd = comb_s(n, b);
        ans = (ans - tmp_nd) % MOD; // Subtract combinations of size b
        //System.out.println(ans + " " + tmp_ans); // Uncomment for debugging
        while(ans < 0){ // Ensure ans is non-negative
            ans += MOD;
        }

        // Output the final result
        System.out.println(ans); // End of the program
    }
}

