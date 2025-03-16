package main

import (
	"fmt"
	"math"
	"math/big"
	"sort"
	"strings"
)

// Constants for maximum limits
const (
	MAX_N         = 1000000
	MAX_N_Int     = 1000000000000
)

// Function to print a slice with a specified separator
func printSlice[T any](s []T, separator string) {
	if len(s) > 0 {
		for i := 0; i < len(s)-1; i++ {
			fmt.Print(s[i], separator)
		}
		fmt.Println(s[len(s)-1])
	}
}

// Function to check if a number is prime
func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	if num == 2 {
		return true
	}
	if num%2 == 0 {
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

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// Function to calculate the least common multiple (LCM)
func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

// Function to find the maximum of three integers
func Max(a, b, c int) int {
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

// Function to find the minimum of three integers
func Min(a, b, c int) int {
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

// Function to check if a float is an integer
func integer(num float64) bool {
	return math.Floor(num) == num
}

// Recursive function to calculate factorial
func fact(num int) *big.Int {
	if num == 0 {
		return big.NewInt(1)
	}
	result := big.NewInt(int64(num))
	for i := num - 1; i > 0; i-- {
		result.Mul(result, big.NewInt(int64(i)))
	}
	return result
}

// Function to count the number of divisors of n
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

// Function to calculate factorial modulo a given number
func factMod(n, mod int) *big.Int {
	result := big.NewInt(1)
	for i := 2; i <= n; i++ {
		result.Mul(result, big.NewInt(int64(i%mod)))
		result.Mod(result, big.NewInt(int64(mod)))
	}
	return result
}

// Function to perform modular exponentiation
func modPow(x, n, mod int) *big.Int {
	result := big.NewInt(1)
	base := big.NewInt(int64(x))
	exp := big.NewInt(int64(n))
	for exp.Cmp(big.NewInt(0)) > 0 {
		if exp.Bit(0) == 1 {
			result.Mul(result, base).Mod(result, big.NewInt(int64(mod)))
		}
		exp.Rsh(exp, 1)
		base.Mul(base, base).Mod(base, big.NewInt(int64(mod)))
	}
	return result
}

// Function to calculate combinations nCr modulo a given number
func combinationMod(n, r, mod int) *big.Int {
	if r > n-r {
		r = n - r
	}
	if r == 0 {
		return big.NewInt(1)
	}
	numerator := factMod(n, mod)
	denominator := modPow(factMod(r, mod).Int64(), mod-2, mod)
	return numerator.Mul(numerator, big.NewInt(int64(denominator))).Mod(result, big.NewInt(int64(mod)))
}

// Function to check if a string is a palindrome
func rev(s string) bool {
	return s == reverseString(s)
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
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

