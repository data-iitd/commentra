package main

import (
	"fmt"
	"math"
)

// 最小公倍数
func gcd(x, y int) int {
	if x < y {
		x, y = y, x
	}
	for y != 0 {
		x, y = y, x%y
	}
	return x
}

// 最大公倍数
func lcm(x, y int) int {
	return x / gcd(x, y) * y
}

// 階乗
func kaijo(k int) int {
	sum := 1
	for i := 1; i <= k; i++ {
		sum *= i
		sum %= 1000000000 + 7
	}
	return sum
}

// for(int i = ; i < ; i++){}

func lmax(s, t int) int {
	if s > t {
		return s
	}
	return t
}

func lmin(s, t int) int {
	if s < t {
		return s
	}
	return t
}

// ここから開始

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	sum := 0
	for b := 1; b <= n; b++ {
		cnt := (n + 1) / b
		md := (n + 1) % b
		sum += cnt * lmax(b-k, 0) + lmax(md-k, 0)
		if k == 0 {
			sum--
		}
	}
	fmt.Println(sum)
}

