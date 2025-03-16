
import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        // Read input from stdin
        Scanner sc = new Scanner(System.in);
        // Initialize variables
        long n;
        long n_tmp;
        long a;
        long b;
        long ans=1;

        n = sc.nextLong();
        a = sc.nextLong();
        b = sc.nextLong();
        // Read input values of n, a, and b from the user

        ans=mod_pow(2,n);
        // Calculate 2^n
        ans--;
        // Subtract 1 from the result

        long tmp_nd;
        // Initialize a temporary variable tmp_nd
        tmp_nd=comb_s(n,a);
        // Calculate nCa

        ans=(ans-tmp_nd)%MOD;
        // Subtract nCa from the result

        while(ans<0){
            // If the result is negative, add MOD to make it positive
            ans+=MOD;
        }

        // Calculate nCb
        tmp_nd=comb_s(n,b);

        ans=(ans-tmp_nd)%MOD;
        // Subtract nCb from the result

        while(ans<0){
            // If the result is negative, add MOD to make it positive
            ans+=MOD;
        }

        System.out.println(ans);
        // Print the final answer
    }

    // Function to calculate x raised to the power n modulo MOD
    public static long mod_pow(long x, long n){
        long ans = 1;
        while(n>0){
            // While n is greater than 0
            if((n&1)==1){
                // If n is odd
                ans = ans * x % MOD;
                // Multiply ans with x
            }
            x = x * x % MOD;
            // Square x and update ans
            n >>= 1;
            // Divide n by 2
        }
        return ans;    
    }
    // End of mod_pow function

    // Function to calculate nCr (n choose r) using combinatorics formula
    public static long comb_s(long n, long r){
        long tmp_n=1;
        long tmp_d=1;
        long ans;
        // Initialize temporary variables tmp_n and tmp_d to 1
        for(int i=1; i<=r; i++){
            // Loop from i=1 to i=r
            tmp_n=(tmp_n*(n+1-i))%MOD;
            // Multiply tmp_n with (n+1-i)
            tmp_d=(tmp_d*i)%MOD;
            // Multiply tmp_d with i
            ans=tmp_n*mod_pow(tmp_d,MOD-2);
            // Calculate ans = tmp_n * (tmp_d^(MOD-2))
        }

        return ans;    
    }
    // End of comb_s function
}
// End of Main class

