
import java.util.*;
import java.io.*;

class s495252714 {
    static final int MOD = 1000000007;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
        }
        Arrays.sort(c);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long)(n + 1 - i) * c[i] % MOD) % MOD;
        }
        ans = ans * modpow(4, n - 1) % MOD;
        System.out.println(ans);
    }

    static int modpow(int a, int n) {
        int res = 1;
        for (; n > 0; n >>= 1) {
            if (n % 2 == 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
        }
        return res;
    }
}

// 