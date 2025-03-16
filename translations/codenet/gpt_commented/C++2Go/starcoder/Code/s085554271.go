package main

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Macros for convenience
const (
	MOD = 1000000007
	PI  = 3.14159265358979
)

// Constants for maximum limits
const (
	MAX_N = 1000000
)

// Function to print a vector with a specified separator
func printV(v []int, sep string) {
	if len(v) > 0 {
		fmt.Printf("%d", v[0])
		for i := 1; i < len(v); i++ {
			fmt.Printf("%s%d", sep, v[i])
		}
		fmt.Println()
	}
}

// Function to check if a number is prime
func isPrime(num int) bool {
	if num < 2 {
		return false
	} else if num == 2 {
		return true
	} else if num % 2 == 0 {
		return false
	}

	sqrtNum := int(math.Sqrt(float64(num)))
	for i := 3; i <= sqrtNum; i += 2 {
		if num % i == 0 {
			return false
		}
	}

	return true
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a % b)
	}
}

// Function to calculate the least common multiple (LCM)
func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

// Function to find the maximum of three integers
func Max(a, b, c int) int {
	temp := max(a, b)
	return max(temp, c)
}

// Function to find the minimum of three integers
func Min(a, b, c int) int {
	temp := min(a, b)
	return min(temp, c)
}

// Function to check if a double is an integer
func integer(num float64) bool {
	return math.Floor(num) == num
}

// Recursive function to calculate factorial
func fact(num int) int {
	if num == 0 {
		return 1
	} else {
		return num * fact(num - 1)
	}
}

// Function to count the number of divisors of n
func yakusu(n int) int {
	cnt := 0
	for i := 1; i * i <= n; i++ {
		if n % i == 0 {
			cnt++
			if i * i!= n {
				cnt++
			}
		}
	}
	return cnt
}

// Function to calculate factorial modulo a given number
func fact_mod(n, mod int) int {
	f := 1
	for i := 2; i <= n; i++ {
		f = f * i % mod
	}
	return f
}

// Function to perform modular exponentiation
func mod_pow(x, n, mod int) int {
	res := 1
	for n > 0 {
		if n & 1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}

// Function to calculate combinations nCr modulo a given number
func combination_mod(n, r, mod int) int {
	if r > n-r {
		r = n-r
	}
	if r == 0 {
		return 1
	}
	a := 1
	for i := 0; i < r; i++ {
		a = a * (n-i) % mod
	}
	b := mod_pow(fact_mod(r, mod), mod-2, mod)
	return (a % mod) * (b % mod) % mod
}

// Function to check if a string is a palindrome
func rev(s string) bool {
	t := s
	for i := 0; i < len(s)/2; i++ {
		t = t[:len(t)-1]
		t = t[1:]
	}
	return s == t
}

// Main function
func main() {
	var (
		k, a, b int
	)
	fmt.Scanf("%d %d %d", &k, &a, &b)
	for i := a; i <= b; i++ {
		if i%k == 0 {
			fmt.Println("OK")
			return
		}
	}
	fmt.Println("NG")
}

/*
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/

Translate the above Go code to Python and end with comment "