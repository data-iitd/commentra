package main

import (
    "fmt"
    "math"
)

const MOD = 1000000007

func mod_pow(x, n int) int {
    ans := 1
    for n > 0 {
        if n&1 == 1 {
            ans = (ans * x) % MOD
        }
        x = (x * x) % MOD
        n >>= 1
    }
    return ans
}

func comb_s(n, r int) int {
    tmp_n := 1
    tmp_d := 1
    ans := 1
    for i := 1; i <= r; i++ {
        tmp_n = (tmp_n * (n + 1 - i)) % MOD
        tmp_d = (tmp_d * i) % MOD
        ans = (tmp_n * mod_pow(tmp_d, MOD-2)) % MOD
    }
    return ans
}

func main() {
    var n, a, b int
    fmt.Scanf("%d %d %d", &n, &a, &b)
    ans := mod_pow(2, n)
    ans--
    tmp_nd := comb_s(n, a)
    ans = (ans - tmp_nd) % MOD
    for ans < 0 {
        ans += MOD
    }
    tmp_nd = comb_s(n, b)
    ans = (ans - tmp_nd) % MOD
    for ans < 0 {
        ans += MOD
    }
    fmt.Println(ans)
}

