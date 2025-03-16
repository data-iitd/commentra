
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math/big"
    "math"
)

// Define a constant value for MOD
const MOD = 1000000007

// Function to calculate x raised to the power n modulo MOD
func mod_pow(x, n int64) int64 {
    ans := int64(1)
    for n > 0 {
        if n&1 == 1 {
            ans = ans * x % MOD
        }
        x = x * x % MOD
        n >>= 1
    }
    return ans
}

// Function to calculate nCr (n choose r) using combinatorics formula
func comb_s(n, r int64) int64 {
    tmp_n := int64(1)
    tmp_d := int64(1)
    ans := int64(1)
    for i := int64(1); i <= r; i++ {
        tmp_n = (tmp_n * (n + 1 - i)) % MOD
        tmp_d = (tmp_d * i) % MOD
        ans = tmp_n * mod_pow(tmp_d, MOD-2)
    }
    return ans
}

func main() {
    var n, a, b int64
<<<<<<< HEAD
    fmt.Scanf("%d %d %d", &n, &a, &b)
=======
    fmt.Scanf("%d %d %d\n", &n, &a, &b)
>>>>>>> 98c87cb78a (data updated)
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

