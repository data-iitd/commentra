package main

import (
	"fmt"
	"math"
)

func isPrime(num int) bool {
	if num < 2 {
		return false
	} else if num == 2 {
		return true
	} else if num%2 == 0 {
		return false // 偶数はあらかじめ除く
	}

	sqrtNum := int(math.Sqrt(float64(num)))
	for i := 3; i <= sqrtNum; i += 2 {
		if num%i == 0 {
			// 素数ではない
			return false
		}
	}

	// 素数である
	return true
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
	//a*bは64bit integer overflow
}

func max(a, b, c int) int {
	if a > b {
		if a > c {
			return a
		}
		return c
	}
	if b > c {
		return b
	}
	return c
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	}
	if b < c {
		return b
	}
	return c
}

func integer(num float64) bool {
	return math.Floor(num) == num
}

func fact(num int) int {
	if num == 0 {
		return 1
	}
	return num * fact(num-1)
}

func yakusu(n int) int {
	cnt := 0
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			cnt++
			if i*i != n {
				cnt++
			}
		}
	}
	return cnt
}

func factMod(n, mod int) int {
	f := 1
	for i := 2; i <= n; i++ {
		f = f * (i % mod) % mod
	}
	return f
}

// 繰り返し二乗法 (modの世界での累乗)
func modPow(x, n, mod int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}

// 組み合わせ nCr を求める
func combinationMod(n, r, mod int) int {
	if r > n-r {
		r = n - r
	}
	if r == 0 {
		return 1
	}
	a := 1
	for i := 0; i < r; i++ {
		a = a * (n - i) % mod
	}
	b := modPow(factMod(r, mod), mod-2, mod)
	return a * b % mod
}

func rev(s string) bool {
	t := s
	for i := 0; i < len(s)/2; i++ {
		s[i], s[len(s)-1-i] = s[len(s)-1-i], s[i]
	}
	return s == t
}

func main() {
	var a, b, c, n, m, k, x, y int
	var ans int
	var str, s, t, u string

	fmt.Scan(&k, &a, &b)
	for i := a; i <= b; i++ {
		if i%k == 0 {
			fmt.Println("OK")
			return
		}
	}
	fmt.Println("NG")
}

