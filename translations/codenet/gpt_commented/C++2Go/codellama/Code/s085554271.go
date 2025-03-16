
package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

// Macros for convenience
const (
	MOD  = 1000000007
	Int  = int64
	PI   = 3.14159265358979
	IOS  = 0
	prec = 15
	endl = "\n"
)

// Constants for maximum limits
const (
	MAX_N = 1000000
	MAX_N_Int = 1000000000000
)

// Function to print a vector with a specified separator
func printV(v []int, separator string) {
	if len(v) > 0 {
		for i := 0; i < len(v) - 1; i++ {
			fmt.Printf("%d%s", v[i], separator)
		}
		fmt.Printf("%d\n", v[len(v) - 1])
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

	sqrtNum := math.Sqrt(float64(num))
	for i := 3; i <= int(sqrtNum); i += 2 {
		if num % i == 0 {
			return false
		}
	}

	return true
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b Int) Int {
	if b != 0 {
		return gcd(b, a % b)
	}
	return a
}

// Function to calculate the least common multiple (LCM)
func lcm(a, b Int) Int {
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
func fact(num int) Int {
	if num == 0 {
		return 1
	}
	return Int(num) * fact(num - 1)
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
func fact_mod(n, mod Int) Int {
	f := 1
	for i := 2; i <= n; i++ {
		f = (f * (i % MOD)) % MOD
	}
	return f
}

// Function to perform modular exponentiation
func mod_pow(x, n, mod Int) Int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

// Function to calculate combinations nCr modulo a given number
func combination_mod(n, r, mod Int) Int {
	if r > n-r {
		r = n - r
	}
	if r == 0 {
		return 1
	}
	a := 1
	for i := 0; i < r; i++ {
		a = (a * ((n - i) % mod)) % mod
	}
	b := mod_pow(fact_mod(r, mod), mod - 2, mod)
	return (a % mod) * (b % mod) % mod
}

// Function to check if a string is a palindrome
func rev(s string) bool {
	t := s
	sort.Slice([]byte(s), func(i, j int) bool {
		return s[i] < s[j]
	})
	return t == s
}

// Main function
func main() {
	IOS // Optimize input/output
	prec // Set precision for output
	var a, b, c, n, m, k, x, y int = 0, 0, 0, 0, 0, 0, 0, 0
	var str, s, t, u string = "", "", "", ""
	fmt.Scan(&k, &a, &b) // Input values for k, a, and b

	// Check for multiples of k in the range [a, b]
	for i := a; i <= b; i++ {
		if i%k == 0 {
			fmt.Println("OK") // Output OK if a multiple is found
			return
		}
	}
	fmt.Println("NG") // Output NG if no multiples are found

	fmt.Println() // Print a newline
}

