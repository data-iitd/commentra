import java.util.*;

public class Main {
    static final long INF = 1001001001001001L;
    static final int inf = 1000000007;
    static final long MOD = 1000000007L;
    static final double PI = 3.1415926535897932;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        long[] a = new long[n];
        long[] acc = new long[n + 1];
        
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
            acc[i + 1] = (acc[i] + a[i]) % MOD;
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (a[i] % MOD) * ((MOD + acc[n] - acc[i + 1]) % MOD)) % MOD) % MOD;
        }
        
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
