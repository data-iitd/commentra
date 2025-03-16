
package main

import (
	"fmt"
	"math"
	"math/rand"
	"strconv"
	"strings"
	"time"
)

// Define constants for large numbers and modular arithmetic
const (
	BIG  = 2000000007
	VERYBIG  = 20000000000000007
	MOD  = 1000000007
	FOD   = 998244353
)

// Define types for unsigned and signed long long integers
type ull int64
type sll int64

// Define maximum size for arrays
const N_MAX = 1048576

// Define M_PI if not already defined
const M_PI = 3.14159265358979323846264338327950

// Define structures for various data types
type hwll struct {
	a sll
	b sll
}

type hwllc struct {
	a sll
	b sll
	c sll
}

type linell struct {
	a hwll
	b hwll
}

type hwreal struct {
	a float64
	b float64
}

// Global variables for various parameters
var n, m sll // Dimensions or counts
var h, w sll // Height and width
var k sll // Some parameter
var q sll // Query count
var va, vb, vc, vd, ve, vf sll // Various signed long long variables
var ua, ub, uc, ud, ue, uf ull // Various unsigned long long variables
var vra, vrb, vrc float64 // Various long double variables
var vda, vdb, vdc float64 // Various double variables
var ch, dh byte // Character variables

// Function to return the minimum of two unsigned long long integers
func umin(x, y ull) ull {
	if x < y {
		return x
	}
	return y
}

// Function to return the maximum of two unsigned long long integers
func umax(x, y ull) ull {
	if x > y {
		return x
	}
	return y
}

// Function to return the minimum of two signed long long integers
func smin(x, y sll) sll {
	if x < y {
		return x
	}
	return y
}

// Function to return the maximum of two signed long long integers
func smax(x, y sll) sll {
	if x > y {
		return x
	}
	return y
}

// Function to compute the greatest common divisor (GCD) of two unsigned long long integers
func gcd(x, y ull) ull {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

// Function to compute a^x mod modulo using binary exponentiation
func bitpow(a, x, modulo ull) ull {
	result := ull(1)
	for x > 0 {
		if x&1 == 1 {
			result *= a
			result %= modulo
		}
		x >>= 1
		a = (a * a) % modulo
	}
	return result
}

// Function to perform modular division a / b mod modulo
func divide(a, b, modulo ull) ull {
	return (a * bitpow(b, modulo-2, modulo)) % modulo
}

// Function to return the absolute difference between two unsigned long long integers
func udiff(a, b ull) ull {
	if a < b {
		return b - a
	}
	return a - b
}

// Function to return the absolute difference between two signed long long integers
func sdiff(a, b sll) sll {
	if a < b {
		return b - a
	}
	return a - b
}

// Function to count the number of set bits in an unsigned long long integer
func bitcount(n ull) int {
	result := 0
	for n > 0 {
		if n&1 == 1 {
			result++
		}
		n >>= 1
	}
	return result
}

// Macros for comparison functions
type pullcomp func(left, right *ull) int32
type prevcomp func(left, right *sll) int32
type psllcomp func(left, right *sll) int32
type pcharcomp func(left, right *byte) int32
type pdoublecomp func(left, right *float64) int32

// Comparison function for unsigned long long integers
func pullcomp(left, right *ull) int32 {
	l, r := *left, *right
	if l < r {
		return -1
	}
	if l > r {
		return 1
	}
	return 0
}

// Comparison function for signed long long integers in reverse order
func prevcomp(left, right *sll) int32 {
	l, r := *left, *right
	if l > r {
		return -1
	}
	if l < r {
		return 1
	}
	return 0
}

// Comparison function for signed long long integers
func psllcomp(left, right *sll) int32 {
	l, r := *left, *right
	if l < r {
		return -1
	}
	if l > r {
		return 1
	}
	return 0
}

// Comparison function for characters
func pcharcomp(left, right *byte) int32 {
	l, r := *left, *right
	if l < r {
		return -1
	}
	if l > r {
		return 1
	}
	return 0
}

// Comparison function for double values
func pdoublecomp(left, right *float64) int32 {
	l, r := *left, *right
	if l < r {
		return -1
	}
	if l > r {
		return 1
	}
	return 0
}

// Comparison function for strings
func pstrcomp(left, right *string) int32 {
	l, r := *left, *right
	return strings.Compare(l, r)
}

// Comparison function for hwll structures based on fields a and b
func phwllABcomp(left, right *hwll) int32 {
	l, r := *left, *right
	if l.a < r.a {
		return -1
	}
	if l.a > r.a {
		return 1
	}
	if l.b < r.b {
		return -1
	}
	if l.b > r.b {
		return 1
	}
	return 0
}

// Comparison function for hwll structures in reverse order
func phwllREVcomp(left, right *hwll) int32 {
	l, r := *left, *right
	if l.b < r.b {
		return -1
	}
	if l.b > r.b {
		return 1
	}
	if l.a < r.a {
		return -1
	}
	if l.a > r.a {
		return 1
	}
	return 0
}

// Comparison function for hwllc structures based on fields a, b, and c
func ptriplecomp(left, right *hwllc) int32 {
	l, r := *left, *right
	if l.a < r.a {
		return -1
	}
	if l.a > r.a {
		return 1
	}
	if l.b < r.b {
		return -1
	}
	if l.b > r.b {
		return 1
	}
	if l.c < r.c {
		return -1
	}
	if l.c > r.c {
		return 1
	}
	return 0
}

// Comparison function for hwllc structures in reverse order
func ptripleREVcomp(left, right *hwllc) int32 {
	l, r := *left, *right
	if l.b < r.b {
		return -1
	}
	if l.b > r.b {
		return 1
	}
	if l.a < r.a {
		return -1
	}
	if l.a > r.a {
		return 1
	}
	if l.c < r.c {
		return -1
	}
	if l.c > r.c {
		return 1
	}
	return 0
}

// Comparison function for hwllc structures based on field c, then a, then b
func ptripleCABcomp(left, right *hwllc) int32 {
	l, r := *left, *right
	if l.c < r.c {
		return -1
	}
	if l.c > r.c {
		return 1
	}
	if l.a < r.a {
		return -1
	}
	if l.a > r.a {
		return 1
	}
	if l.b < r.b {
		return -1
	}
	if l.b > r.b {
		return 1
	}
	return 0
}

// Comparison function for hwreal structures based on fields a and b
func phwrealcomp(left, right *hwreal) int32 {
	l, r := *left, *right
	if l.a < r.a {
		return -1
	}
	if l.a > r.a {
		return 1
	}
	if l.b < r.b {
		return -1
	}
	if l.b > r.b {
		return 1
	}
	return 0
}

// Comparison function for linell structures based on their components
func pquadcomp(left, right *linell) int32 {
	l, r := *left, *right
	if phwllABcomp(&l.a, &r.a) != 0 {
		return phwllABcomp(&l.a, &r.a)
	}
	if phwllABcomp(&l.b, &r.b) != 0 {
		return phwllABcomp(&l.b, &r.b)
	}
	return 0
}

// Comparison function for hwllc structures based on a fraction
func pfracomp(left, right *hwllc) int32 {
	l, r := *left, *right
	if l.a*r.b < l.b*r.a {
		return -1
	}
	if l.a*r.b > l.b*r.a {
		return 1
	}
	return 0
}

// Function to check if a value x is within a range [left, right]
func isinrange(left, x, right sll) bool {
	return left <= x && x <= right
}

// Function to check if a value x is within a range [left, right] or vice versa
func isinrange_soft(left, x, right sll) bool {
	return left <= x && x <= right || left >= x && x >= right
}

// Function to swap two signed long long integers
func sw(l, r *sll) {
	if *l == *r {
		return
	}
	t := *l
	*l = *r
	*r = t
}

// Arrays for factorials and their inverses
var frac [N_MAX * 3]ull
var invf [N_MAX * 3]ull

// Function to compute n choose r modulo m
func ncr(n, r, m ull) ull {
	if n < 0 || r < 0 || n < r {
		return 0
	}
	return frac[n] * (invf[r] * invf[n-r] % m) % m
}

// Arrays for various data types
var a [N_MAX + 5]sll
var b [N_MAX + 5]sll
var c [N_MAX + 5]sll
var d [N_MAX + 5]sll
var e [N_MAX * 4]sll
var s [N_MAX + 1]byte
var t [N_MAX + 1]byte
var u [N_MAX + 1]byte
var xy [N_MAX + 5]hwll
var tup [N_MAX + 5]hwllc
var table [3005][3005]sll
var gin [N_MAX]ull

// Initialize counters and arrays for computations
var cnt [3]sll
var pcnt sll
var x [3005][3005]ull

// Initialize factorials and their inverses
func init() {
	for i := ull(0); i < N_MAX*3; i++ {
		frac[i] = i + 1
		invf[i] = bitpow(i+1, MOD-2, MOD)
	}
}

// Main solving function
func solve() ull {
	var i, j, ki, li sll
	var result ull // Variable to store the result
	var maybe ull // Variable for potential calculations
	var sum sll // Variable for summation
	var item sll // Temporary variable
	var dpcell *ull // Pointer for dynamic cell references

	// Initialize result
	result = 1

	// Process the input string and calculate the result based on color counts
	for i = 0; i < n*3; i++ {
		var v ull
		switch s[i] {
		case 'R':
			v = 0 // Red
		case 'G':
			v = 1 // Green
		case 'B':
			v = 2 // Blue
		}

		// Check if there are available colors to form combinations
		if cnt[(v+1)%3] && cnt[(v+2)%3] {
			result *= pcnt // Multiply by the count of available combinations
			pcnt-- // Decrease the count of available combinations
			result %= FOD // Apply modulo
			cnt[(v+1)%3]-- // Decrease count of the first color
			cnt[(v+2)%3]-- // Decrease count of the second color
		} else {
			// If there are more of the other two colors than the current color
			if cnt[(v+1)%3]+cnt[(v+2)%3] > cnt[v] {
				result *= cnt[(v+1)%3] + cnt[(v+2)%3] - cnt[v]
				result %= FOD // Apply modulo
				pcnt++ // Increase the count of available combinations
			}
			cnt[v]++ // Increase count of the current color
		}
	}

	// Calculate the factorial of n for final result
	for i = 1; i <= n; i++ {
		result *= ull(i)
		result %= FOD
	}

	// Output the result
	fmt.Println(result)
	return 0
}

// Main function to execute the program
func main() {
	var i, j int32

	n = 4 // Set initial value for n
	m = 0 // Set initial value for m

	// Read input values
	fmt.Scan(&n, &m)
	fmt.Scan(&s) // Read the string input

	// Call the solve function to compute the result
	solve()
}

