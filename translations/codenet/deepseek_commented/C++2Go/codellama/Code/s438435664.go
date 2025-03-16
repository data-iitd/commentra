
package main

import (
	"fmt"
)

// 最小公倍数
// Computes the greatest common divisor of two numbers x and y
func gcd(x, y int64) int64 {
	tmp := 0
	if x < y {
		tmp = x
		x = y
		y = tmp
	}
	for y > 0 {
		r := x % y
		x = y
		y = r
	}
	return x
}

// 最大公倍数
// Computes the least common multiple of two numbers x and y
func lcm(x, y int64) int64 {
	return x / gcd(x, y) * y
}

// 階乗
// Computes the factorial of a number k modulo 10^9 + 7
func kaijo(k int64) int64 {
	sum := 1
	for i := int64(1); i <= k; i++ {
		sum *= i
		sum %= 1000000000 + 7
	}
	return sum
}

// for(int i = ; i < ; i++){}

// Utility functions to find the maximum and minimum of two numbers
func lmax(s, t int64) int64 {
	if s > t {
		return s
	} else {
		return t
	}
}

func lmin(s, t int64) int64 {
	if s < t {
		return s
	} else {
		return t
	}
}

// ここから開始

func main() {
	// Read two integers n and k
	var n, k int
	fmt.Scan(&n, &k)
	sum := int64(0)

	// Iterate over possible values of b
	for b := 1; b <= n; b++ {
		// Calculate the count and remainder
		cnt := (n + 1) / b
		md := (n + 1) % b

		// Update the sum based on the conditions involving k
		sum += cnt * max((b - k), 0) + max((md - k), 0)

		// Adjust the sum if k is 0
		if k == 0 {
			sum--
		}
	}

	// Print the computed sum
	fmt.Println(sum)
}

// 