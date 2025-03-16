#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD2 1000000007
#define MOD 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

var fact [1100000] Int
var revfact [1100000] Int
var rev [1100000] Int

func init(){
    var m Int = MOD
    fact[0] = 1
    revfact[0] = 1
    rev[0] = 0
    rev[1] = 1
    for i := 1; i < 1100000; i++ {
        fact[i] = fact[i-1] * i % m
        if i>1 rev[i] = MOD / i * (MOD-rev[MOD % i]) % MOD
        revfact[i] = revfact[i-1] * rev[i] % MOD
    }
}

var comb [1100][1100] Int

func nCk(n, k Int) Int {
    if n < k return 0
    if comb[n][k] != 0 return comb[n][k]
    var res Int = comb[n][k]
    return res = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD
}

func mod_pow(x, a, m Int) Int {
    if a == 0 return 1
    var res Int = mod_pow(x, a / 2, m)
    res = res * res % m
    if a % 2 res *= x
    return res % m
}

func inv(x, m Int) Int {
    return mod_pow(x, m-2, m)
}

var aall, ball Int
var n, ans Int
var a [440] Int
var b [440] Int
var dp [440][440][2][2] Int

func main(){
    init()
    fmt.Scan(&n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i], &b[i])
        aall += a[i]
        ball += b[i]
    }

    dp[0][0][0][0] = 1
    for i := 1; i <= n; i++ {
        id := i % 2
        for asum := aall; asum >= 0; asum-- {
            for cnt := 0; cnt <= ball; cnt++ {
                for p := 0; p < 2; p++ {
                    if asum-a[i-1] < 0 continue
                    pw := 1
                    for use := 0; use < b[i-1]; use++ {
                        if cnt-use >= 0 {
                            tmp :=  nCk(cnt, use) % MOD * pw %  MOD
                            dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp % MOD
                            dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp % MOD
                        } else break
                        pw = pw * a[i-1] % MOD
                    }
                    if cnt-b[i-1]+1 >= 0
                        dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-b[i-1]+1][p^1][0] * nCk(cnt, b[i-1]-1) % MOD * pw %  MOD
                    dp[asum][cnt][p][0] %= MOD
                    dp[asum][cnt][p][1] %= MOD
                }
            }
        }
    }

    for asum := 0; asum <= aall; asum++ {
        rev_asum_pow := 1
        for cnt := 0; cnt <= ball; cnt++ {
            rev_asum_pow = rev_asum_pow * rev[asum] % MOD
            for p := 0; p < 2; p++ {
                x := dp[asum][cnt][p][1] * rev_asum_pow  % MOD * (cnt+1) % MOD * aall % MOD * rev[asum] % MOD
                if p == 1 ans += x
                else ans -= x
                ans %= MOD
            }
        }
    }
    if ans < 0 ans += MOD
    fmt.Println(ans)
    
    return 0
}

