
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Define maximum values for different data types
const (
	intmax = math.MaxInt32
	lmax   = math.MaxInt64
	uintmax = math.MaxUint32
	ulmax   = math.MaxUint64
	llmax   = math.MaxInt64
	ll      = int64
)

// Macros for loop iterations
func rep(i, a, n int) {
	for ; i < n; i++ {
		a = i
	}
}

func rrp(i, n, a int) {
	for ; i >= a; i-- {
		a = i
	}
}

// Define vector types for convenience
type llvec [][]ll
type charvec [][]char
type llpvec []pair

// Mathematical constants and utility functions
const pi = math.Acos(-1)

func cei(x, y ll) ll {
	ans := x / y
	if x%y != 0 {
		ans++
	}
	return ans
}

func gcd(x, y ll) ll {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

func lcm(x, y ll) ll {
	return x / gcd(x, y) * y
}

func llpow(x, n ll) ll {
	ans := 1
	for i := 0; i < int(n); i++ {
		ans *= x
	}
	return ans
}

func fact(x ll) ll {
	ans := 1
	for i := 0; i < int(x); i++ {
		ans *= (x - ll(i))
	}
	return ans
}

func ncr(n, r ll) ll {
	return fact(n) / fact(r) / fact(n-r)
}

func npr(n, r ll) ll {
	return fact(n) / fact(n-r)
}

func prime(a ll) bool {
	if a <= 1 {
		return false
	}
	for i := 2; i*i <= a; i++ {
		if a%i == 0 {
			return false
		}
	}
	return true
}

func fib(x ll) ll {
	fibo := make([]ll, x+10)
	fibo[0] = 1
	fibo[1] = 1
	fibo[2] = 1
	for i := 3; i < x+1; i++ {
		fibo[i] = fibo[i-1] + fibo[i-2]
	}
	return fibo[x]
}

func dig(n ll) ll {
	d := 0
	for n/10 > 0 {
		d++
		n /= 10
	}
	return d
}

// Variable declarations
var (
	h, w ll
	t   []rune
	s   = "snuke"
)

func main() {
	// Read height and width of the grid
	fmt.Scan(&h, &w)

	// Initialize a temporary character array and the target string
	t = make([]rune, 10)

	// Iterate through the grid to find the target string
	for i := 0; i < int(h); i++ {
		for j := 0; j < int(w); j++ {
			// Read the current string from input
			fmt.Scan(&t)
			// Check if the current string matches the target string
			if strings.Compare(string(t), s) == 0 {
				// If found, calculate the position and print it
				c := 'A' + rune(j) // Convert column index to character
				fmt.Printf("%c%d\n", c, i+1) // Output the position in the required format
				os.Exit(0) // Exit the program after finding the target
			}
		}
	}

	// Return 0 to indicate successful execution
	os.Exit(0)
}

