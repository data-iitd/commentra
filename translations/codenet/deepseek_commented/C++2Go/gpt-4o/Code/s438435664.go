package main

import (
	"fmt"
)

func gcd(x, y int64) int64 {
	if x < y {
		x, y = y, x
	}
	for y > 0 {
		r := x % y
		x = y
		y = r
	}
	return x
}

func lcm(x, y int64) int64 {
	return x / gcd(x, y) * y
}

func kaijo(k int64) int64 {
	const mod = 1000000007
	sum := int64(1)
	for i := int64(1); i <= k; i++ {
		sum = (sum * i) % mod
	}
	return sum
}

func lmax(s, t int64) int64 {
	if s > t {
		return s
	}
	return t
}

func lmin(s, t int64) int64 {
	if s < t {
		return s
	}
	return t
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	var sum int64 = 0

	for b := 1; b <= n; b++ {
		cnt := (n + 1) / b
		md := (n + 1) % b

		sum += int64(cnt) * lmax(int64(b-k), 0) + lmax(int64(md-k), 0)

		if k == 0 {
			sum--
		}
	}

	fmt.Println(sum)
}

// <END-OF-CODE>
