
import java.util.*;
import java.io.*;

class s789380051 {
    static final long MOD = 1000000007;

    static long mod_pow(long x, long n){
        long ans = 1;
        while(n>0){
            if((n&1)==1){
                ans = ans * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return ans;
    }

    static long comb_s(long n, long r){
        long tmp_n=1;
        long tmp_d=1;
        long ans;
        for(int i=1; i<=r; i++){
            tmp_n=(tmp_n*(n+1-i))%MOD;
            tmp_d=(tmp_d*i)%MOD;
            ans=tmp_n*mod_pow(tmp_d,MOD-2);
        }

        return ans;    
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long ans=1;

        ans=mod_pow(2,n);
        ans--;
        long tmp_nd;
        tmp_nd=comb_s(n,a);
        ans=(ans-tmp_nd)%MOD;
        while(ans<0){
            ans+=MOD;
        }
        //cout << ans << " " << tmp_ans << endl;

        tmp_nd=comb_s(n,b);
        ans=(ans-tmp_nd)%MOD;
        //cout << ans << " " << tmp_ans << endl;
        while(ans<0){
            ans+=MOD;
        }

        System.out.println(ans);
    }
}

