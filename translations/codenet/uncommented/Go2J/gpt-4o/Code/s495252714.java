import java.util.*;
import java.io.*;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        int n = Integer.parseInt(br.readLine());
        int[] c = new int[n];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            c[i] = Integer.parseInt(st.nextToken());
        }
        
        long ans = 0;
        Arrays.sort(c);
        
        for (int i = 0; i < n; i++) {
            ans = (ans + (long)(n + 1 - i) * c[i] % MOD) % MOD;
        }
        
        pw.println(ans * modpow(4, n - 1) % MOD);
        pw.flush();
    }

    private static long modpow(int a, int n) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * a % MOD;
            }
            a = (long)a * a % MOD;
            n >>= 1;
        }
        return res;
    }
}

//<END-OF-CODE>
