
package main

import "fmt"

func main() {
	mod := 1000000007
	var n int
	fmt.Scan(&n)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&c[i])
	}
	c = c[:n]
	c = c[n-1:]
	b := pow(2, 2*n-2, mod)
	a := 2 * b % mod
	ans := 0
	for i := 0; i < n; i++ {
		ans += c[i] * (a + i*b)
		ans %= mod
	}
	fmt.Println(ans)
}

func pow(a, b, c int) int {
	ans := 1
	for b > 0 {
		if b&1 == 1 {
			ans = ans * a % c
		}
		a = a * a % c
		b >>= 1
	}
	return ans
}

