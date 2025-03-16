package main

import "fmt"

// Define a constant for modulo operation
const MOD = 1000000007

// Function to compute (x^n) % MOD using modular exponentiation
func modPow(x, n int) int {
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

// Function to compute combination C(n, r) % MOD using modular arithmetic
func comb(n, r int) int {
    tmp_n := 1
    tmp_d := 1
    ans := 1
    for i := 1; i <= r; i++ {
        tmp_n = (tmp_n * (n + 1 - i)) % MOD
        tmp_d = (tmp_d * i) % MOD
        ans = (tmp_n * modPow(tmp_d, MOD-2)) % MOD
    }
    return ans
}

func main() {
    var n, a, b int
    fmt.Scan(&n, &a, &b)
    ans := 1
    ans = modPow(2, n)
    ans--
    tmp_nd := comb(n, a)
    ans = (ans - tmp_nd) % MOD
    for ans < 0 {
        ans += MOD
    }
    tmp_nd = comb(n, b)
    ans = (ans - tmp_nd) % MOD
    for ans < 0 {
        ans += MOD
    }
    fmt.Println(ans)
}

