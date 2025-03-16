
package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

// Include necessary standard libraries

type ll int64
type ld float64

// Define custom data types

const (
	INF   = 1 << 60
	MOD1  = 1000000007
	MOD2  = 998244353
	MAX_N = 1 << 20
	YES   = "Yes\n"
	NO    = "No\n"
	PN    = "\n"
	PI    = 3.141592653589793238
)

// Constants and definitions

func swap(a, b *ll) {
	c := *b
	*b = *a
	*a = c
}

// Function to swap two variables

func cin(n *ll) {
	fmt.Scanf("%d", n)
}

// Function to read an integer from the standard input

func max2(a, b ll) ll {
	if a >= b {
		return a
	}
	return b
}

// Function to find the maximum of two numbers

func min2(a, b ll) ll {
	if a >= b {
		return b
	}
	return a
}

// Function to find the minimum of two numbers

func min3(a, b, c ll) ll {
	if a <= b && a <= c {
		return a
	}
	if b <= c {
		return b
	}
	return c
}

// Function to find the minimum of three numbers

func max3(a, b, c ll) ll {
	if a >= b && a >= c {
		return a
	}
	if b >= c {
		return b
	}
	return c
}

// Function to find the maximum of three numbers

func minn(n ll, a []ll) ll {
	b := INF
	for i := 0; i < n; i++ {
		b = min2(b, a[i])
	}
	return b
}

// Function to find the minimum number in an array

func maxn(n ll, a []ll) ll {
	b := -INF
	for i := 0; i < n; i++ {
		b = max2(b, a[i])
	}
	return b
}

// Function to find the maximum number in an array

func POW(a, b ll) ll {
	c := 1
	for i := 0; i < b; i++ {
		c *= a
	}
	return c
}

// Function to calculate a^b

func POW_d(a, b ld) ld {
	c := 1.0
	for i := 0; i < b; i++ {
		c *= a
	}
	return c
}

// Function to calculate a^b (double version)

func gcd(a, b ll) ll {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to find the greatest common divisor of two numbers

func lcm(a, b ll) ll {
	return a / gcd(a, b) * b
}

// Function to find the least common multiple of two numbers

func mod_MOD1(n ll) ll {
	n += n < 0
	return n % MOD1
}

// Function to calculate n % MOD1

func mod_p(n, p ll) ll {
	n += n < 0
	return n % p
}

// Function to calculate n % p

func change_into_num(s string, len, p ll) ll {
	return !p || len < p ? 0 : POW(10, p-1)*(s[len-p]-'0') + change_into_num(s, len, p-1)
}

// Function to convert a substring of a string into a number

func digits(a, b ll) ll {
	return a/b > 0 ? 1+digits(a/b, b) : 1
}

// Function to calculate the number of digits in a number

func base(n, a, i ll) ll {
	return i == 1 ? n%a : base(n/a, a, i-1)
}

// Function to calculate the base representation of a number

func is_inArr1(x ll) bool {
	return x < 0 || x >= n
}

// Function to check if a number is within the range of an array

func is_inArr2(y, x, h, w ll) bool {
	return y < 0 || y >= h || x < 0 || x >= w
}

// Function to check if a pair of coordinates is within the range of a rectangle

func lr_lower(l, r *int, am, val ll, type int) {
	// Function to find the lowest index i such that a[i] = val
	// If type is less than 3, then am < val, otherwise am <= val
}

func lr_upper(l, r *int, am, val ll, type int) {
	// Function to find the highest index i such that a[i] = val
	// If type is less than 3, then am <= val, otherwise am < val
}

func cmp_lower(a, b ll, type int) int {
	// Comparison function for lower_bound
	// If type is 1, then a == b, otherwise a < b (type = 2) or a < b (type = 3)
}

func cmp_upper(a, b ll, type int) int {
	// Comparison function for upper_bound
	// If type is 1, then a == b, otherwise a <= b (type = 2) or a < b (type = 3)
}

// Functions for finding the lowest and highest indices of a value in an array

func lower_bound(a []ll, l, r, val ll, type int) ll {
	// Binary search function for finding the lowest index i such that a[i] = val
	// If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)
}

func upper_bound(a []ll, l, r, val ll, type int) ll {
	// Binary search function for finding the highest index i such that a[i] = val
	// If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)
}

// Functions for finding the number of occurrences of a value in an array

func count(a []ll, l, r, x ll) ll {
	// Function to find the number of occurrences of x in the subarray a[l..r]
}

func factor(n, new_common_plus ll) []ll {
	// Function to find the prime factorization of n
	// new_common_plus can be 1 (common factor), 2 (common factor and its power), or 0 (no common factor)
}

func judge_prime(n ll) bool {
	// Function to check if n is prime
}

// Functions for calculating the inverse and multiplicative function of a number modulo another number

func makeinv(x, mod, is_fac ll) ll {
	// Function to calculate the multiplicative inverse of x modulo mod
	// is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)
}

func m_inv(x, mod, is_fac ll) ll {
	// Function to calculate the inverse of x modulo mod
	// is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)
}

func m_f(x, mod ll) ll {
	// Function to calculate the multiplicative function of x modulo mod
}

func mod_nck(n, k, mod ll) ll {
	// Function to calculate nCk modulo mod
}

func m_p(r, n, mod ll) ll {
	// Function to calculate r^n modulo mod
}

func m_mul2(a, b, mod ll) ll {
	// Function to calculate the product of two numbers modulo mod
}

func m_mul3(a, b, c, mod ll) ll {
	// Function to calculate the product of three numbers modulo mod
}

func m_mul4(a, b, c, d, mod ll) ll {
	// Function to calculate the product of four numbers modulo mod
}

func m_mul5(a, b, c, d, e, mod ll) ll {
	// Function to calculate the product of five numbers modulo mod
}

// Functions for sorting arrays

func upll(a, b ll) int {
	if a < b {
		return -1
	}
	if a > b {
		return 1
	}
	return 0
}

func downll(a, b ll) int {
	if a < b {
		return 1
	}
	if a > b {
		return -1
	}
	return 0
}

func cmp_string(a, b string) int {
	return strings.Compare(a, b)
}

func cmp_char(a, b byte) int {
	return int(a) - int(b)
}

func sortup(a []ll) {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}

func sortdown(a []ll) {
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })
}

func sort_string(a []string) {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}

func sort_char(a string) {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}

// Function to find the number of unique elements in an array or a string

func unique_string(n ll, size ll, a []string) ll {
	ans := 1
	for i := 1; i < n; i++ {
		if a[i] != a[i-1] {
			ans++
		}
	}
	return ans
}

func unique_num(n ll, a []ll) ll {
	ans := 1
	for i := 1; i < n; i++ {
		if a[i] != a[i-1] {
			ans++
		}
	}
	return ans
}

// Global variables and constants

var s []string

func main() {
	// Main function

	var l, r, d ll
	var ans ll

	fmt.Scan(&l)
	fmt.Scan(&r)
	fmt.Scan(&d)

	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}

	fmt.Println(ans)

	return
}

