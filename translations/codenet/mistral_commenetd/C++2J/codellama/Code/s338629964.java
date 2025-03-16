
#######
// Including necessary libraries
import java.util.*;
import java.math.*;

// Defining some constants and variables
final int MOD2 = 1000000007;
final int MOD = 998244353;
final int INF = (1<<30)-1;
final int LINF = (1LL<<60);
final double EPS = (1e-10);

// Defining some arrays and functions
int fact[] = new int[1100000];
int revfact[] = new int[1100000];
int rev[] = new int[1100000];

void init(){
    int m = MOD;
    fact[0] = 1;
    revfact[0] = 1;
    rev[0] = 0;
    rev[1] = 1;
    for(int i = 1;i < 1100000;i++){
        fact[i] = fact[i-1] * i % m;
        if(i>1)rev[i] = MOD / i * (MOD-rev[MOD % i]) % MOD;
        revfact[i] = revfact[i-1] * rev[i] % MOD;
    }
}

int comb[][] = new int[1100][1100];

int nCk(int n, int k){
    if(n < k)return 0;
    if(comb[n][k] != 0)return comb[n][k];
    int &res = comb[n][k];
    return res = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD;
}

int mod_pow(int x, int a, int m = MOD){
    if(a == 0)return 1;
    int res = mod_pow(x, a / 2, m);
    res = res * res % m;
    if(a % 2)res *= x;
    return res % m;
}

int inv(int x, int m = MOD){
    return mod_pow(x, m-2, m);
}

// Defining some variables and reading input from the user
int aall, ball;
int n, ans;
int a[] = new int[440];
int b[] = new int[440];

Scanner sc = new Scanner(System.in);
n = sc.nextInt();
for(int i = 0;i < n;i++){
    a[i] = sc.nextInt();
    b[i] = sc.nextInt();
    aall += a[i];
    ball += b[i];
}

// Calculating the answer using dynamic programming
int main(){
    init();
    dp[0][0][0][0] = 1;
    for(int i = 1;i <= n;i++){
        int id = i % 2;
        for(int asum = aall;asum >= 0;asum--){
            for(int cnt = 0;cnt <= ball;cnt++){
                for(int p = 0;p < 2;p++){
                    if(asum-a[i-1] < 0)continue;
                    int pw = 1;
                    for(int use = 0;use < b[i-1];use++){
                        if(cnt-use >= 0){
                            int tmp =  nCk(cnt, use) % MOD * pw %  MOD;
                            dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp % MOD;
                            dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp % MOD;
                        }
                        else break;
                        pw = pw * a[i-1] % MOD;
                    }
                    if(cnt-b[i-1]+1 >= 0)
                        dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-b[i-1]+1][p^1][0] * nCk(cnt, b[i-1]-1) % MOD * pw %  MOD;
                    dp[asum][cnt][p][0] %= MOD;
                    dp[asum][cnt][p][1] %= MOD;
                }
            }
        }
    }

    for(int asum = 0;asum <= aall;asum++){
        int rev_asum_pow = 1;
        for(int cnt = 0;cnt <= ball;cnt++){
            rev_asum_pow = rev_asum_pow * rev[asum] % MOD;
            for(int p = 0;p < 2;p++){
                int x = dp[asum][cnt][p][1] * rev_asum_pow  % MOD * (cnt+1) % MOD * aall % MOD * rev[asum] % MOD;
                if(p == 1)ans += x;
                else ans -= x;
                ans %= MOD;
            }
        }
    }

    if(ans < 0)ans += MOD;
    System.out.println(ans);

    return 0;
}

