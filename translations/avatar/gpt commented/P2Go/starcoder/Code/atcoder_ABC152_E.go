package main

import (
	"fmt"
	"math/big"
)

// gcd returns the greatest common divisor of a and b.
func gcd(a, b int) int {
	for b!= 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}

// lcm returns the least common multiple of a and b.
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	for i := range a {
		fmt.Scanf("%d", &a[i])
	}
	var ans big.Int
	ans.SetInt64(1)
	for _, v := range a {
		ans.Mul(&ans, big.NewInt(int64(v)))
		ans.Mod(&ans, big.NewInt(int64(MOD)))
	}
	for _, v := range a {
		ans.Mul(&ans, big.NewInt(int64(pow(v, MOD-2, MOD))))
		ans.Mod(&ans, big.NewInt(int64(MOD)))
	}
	fmt.Println(ans.Int64() % MOD)
}

// pow returns a^b % m.
func pow(a, b, m int) int {
	a %= m
	r := 1
	for b > 0 {
		if b&1 > 0 {
			r = r * a % m
		}
		a = a * a % m
		b >>= 1
	}
	return r
}

