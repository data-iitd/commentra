package main

import (
	"fmt"
)

func gcd(a, b int64) int64 {
	var c int64
	for b > 0 {
		c = a % b
		a = b
		b = c
	}
	return a
}

func modpow(a, n, mod int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n&1 == 1 {
			ans = ans * a % mod
		}
		a = a * a % mod
		n /= 2
	}
	return ans
}

func modinv(a, mod int64) int64 {
	return modpow(a, mod-2, mod)
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func chmax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	sum := 0
	m := n
	for i := 0; i < 9; i++ {
		sum += n % 10
		n /= 10
	}
	if m%sum == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
