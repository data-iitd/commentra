
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 100000007

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(in, "%d\n", &n)
	const M = 1000000
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(in, "%d", &a[i])
	}
	const Nsq = 1000
	fact := make([]int, M)
	fact[0] = 1
	for i := 1; i < Nsq; i++ {
		fact[i] = int(int64(fact[i-1]) * int64(i) % MOD)
	}
	for i := 1; i < Nsq; i++ {
		fact[i] = int(int64(fact[i-1]) * int64(fact[i]) % MOD)
	}
	inv := make([]int, n)
	for i := 0; i < n; i++ {
		inv[i] = int(pow(int64(i+1), MOD-2, MOD))
	}
	sum := int64(0)
	for i := 0; i < n; i++ {
		sum += int64(inv[i]) + int64(inv[n-1-i]) - 1
	}
	sum %= MOD
	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += int64(a[i]) * sum
	}
	ans %= MOD
	ans *= int64(fact[n])
	ans %= MOD
	fmt.Fprintf(out, "%d\n", ans)
	out.Flush()
}

func pow(x, n, mod int64) int64 {
	y := int64(1)
	for n > 0 {
		if n&1 == 1 {
			y = y * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return y
}

