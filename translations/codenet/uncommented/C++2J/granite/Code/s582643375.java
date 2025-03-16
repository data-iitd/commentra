
import java.util.*;
import java.io.*;

class s582643375 {
    static final int MOD = 100000007;
    static final int MAX = 1000010;
    static long[] fac = new long[MAX];
    static long[] finv = new long[MAX];
    static long[] inv = new long[MAX];

    public static void main(String[] args) throws IOException {
        init();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int X = Integer.parseInt(str[0]);
        int Y = Integer.parseInt(str[1]);
        if((X+Y)%3!= 0){
            System.out.println(0);
            return;
        }
        int n = (X+Y)/3+1;
        int k = 2*(n-1)-Y+1; // y = 2xより最も上にくる点からどれだけ離れているか。
        System.out.println(C(n-1, k-1));
    }

    static void init(){
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i < MAX; i++){
            fac[i] = fac[i-1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
            finv[i] = finv[i-1] * inv[i] % MOD;
        }
    }

    static long C(int n, int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
    }
}
