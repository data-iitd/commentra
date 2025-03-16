import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int ans = 1;
        ans = (int) Math.pow(2, n) - 1;
        int tmp_nd;
        tmp_nd = (int) comb_s(n, a);
        ans = (ans - tmp_nd) % 1000000007;
        while(ans < 0){
            ans += 1000000007;
        }
        tmp_nd = (int) comb_s(n, b);
        ans = (ans - tmp_nd) % 1000000007;
        while(ans < 0){
            ans += 1000000007;
        }
        System.out.println(ans);
    }

    // Function to compute (x^n) % MOD using modular exponentiation
    public static long mod_pow(long x, long n){
        long ans = 1;
        while(n > 0){
            if((n & 1) == 1){
                ans = ans * x % 1000000007;
            }
            x = x * x % 1000000007;
            n >>= 1;
        }
        return ans;
    }

    // Function to compute combination C(n, r) % MOD using modular arithmetic
    public static long comb_s(long n, long r){
        long tmp_n = 1;
        long tmp_d = 1;
        long ans;
        for(int i = 1; i <= r; i++){
            tmp_n = (tmp_n * (n + 1 - i)) % 1000000007;
            tmp_d = (tmp_d * i) % 1000000007;
            ans = tmp_n * mod_pow(tmp_d, 1000000007 - 2);
        }
        return ans;
    }
}

