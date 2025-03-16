package main

import (
	"fmt"
	"math"
)

const MOD = 1000000007

func isPrime(num int) bool {
	if num < 2 {
		return false
	} else if num == 2 {
		return true
	} else if num%2 == 0 {
		return false
	}

	sqrtNum := int(math.Sqrt(float64(num)))
	for i := 3; i <= sqrtNum; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func gcd(a, b int64) int64 {
	if b != 0 {
		return gcd(b, a%b)
	}
	return a
}

func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func max(a, b, c int) int {
	return int(math.Max(float64(a), math.Max(float64(b), float64(c))))
}

func min(a, b, c int) int {
	return int(math.Min(float64(a), math.Min(float64(b), float64(c))))
}

func integer(num float64) bool {
	return math.Floor(num) == num
}

func fact(num int) int64 {
	if num == 0 {
		return 1
	}
	return int64(num) * fact(num-1)
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

func factMod(n int64, mod int64) int64 {
	f := int64(1)
	for i := int64(2); i <= n; i++ {
		f = f * (i % mod) % mod
	}
	return f
}

func modPow(x, n, mod int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func combinationMod(n, r, mod int64) int64 {
	if r > n-r {
		r = n - r
	}
	if r == 0 {
		return 1
	}
	a := int64(1)
	for i := int64(0); i < r; i++ {
		a = a * ((n - i) % mod) % mod
	}
	b := modPow(factMod(r, mod), mod-2, mod)
	return (a % mod) * (b % mod) % mod
}

func rev(s string) bool {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r) == s
}

func main() {
	var k, a, b int
	fmt.Scan(&k, &a, &b)

	for i := a; i <= b; i++ {
		if i%k == 0 {
			fmt.Println("OK")
			return
		}
	}
	fmt.Println("NG")
}

// <END-OF-CODE>
