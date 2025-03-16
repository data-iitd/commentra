
import java.io.*;
import java.util.*;

public class s480704678{
    static final long MOD = 1000000007L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(input[i]);
        }

        long[] acc = new long[n + 1];
        acc[0] = 0;
        for (int i = 0; i < n; i++) {
            acc[i + 1] = acc[i] + a[i];
            acc[i + 1] %= MOD;
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD;
            ans %= MOD;
        }
        System.out.println(ans);
    }
}

