
import java.util.*;
import java.io.*;

public class s495252714{
    static final int MOD = 1000000007;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(c);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long)(n+1-i) * c[i] % MOD) % MOD;
        }
        ans = ans * modpow(4, n-1) % MOD;
        System.out.println(ans);
    }

    static int modpow(int a, int n) {
        int res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            n /= 2;
        }
        return res;
    }
}

