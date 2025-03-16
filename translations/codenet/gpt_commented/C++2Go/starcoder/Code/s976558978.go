
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// File pointers for input and output
var _fin = bufio.NewReader(os.Stdin)
var _fout = bufio.NewWriter(os.Stdout)

// Mathematical constants and limits
const PI = 3.141592653589793238462643383279502884197169399375105820974
const ten5p1 = 100001
const ten6p1 = 1000001
const ten8p1 = 100000001
const ten9p1 = 1000000001

// Type definitions for convenience
type uint uint
type ll int64
type ull uint64

// Macros for loop iterations
func rep(var int, n int) {
	for var = 0; var < n; var++ {
	}
}
func repi(n int) {
	rep(i, n) {
	}
}
func repj(n int) {
	rep(j, n) {
	}
}
func repi1(n int) {
	for i := 1; i < n; i++ {
	}
}
func repj1(n int) {
	for j := 1; j < n; j++ {
	}
}

// Macros for min and max operations
func _min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
func _max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// Macros for initializing arrays
func zeroi(data []int, n int) {
	for i := 0; i < n; i++ {
		data[i] = 0
	}
}
func zeroll(data []ll, n int) {
	for i := 0; i < n; i++ {
		data[i] = 0
	}
}
func one(data []int, n int) {
	for i := 0; i < n; i++ {
		data[i] = 1
	}
}

// Functions for reading input
func readc() byte {
	var var byte
	fmt.Fscanf(_fin, "%c", &var)
	return var
}
func readi() int {
	var var int
	fmt.Fscanf(_fin, "%d", &var)
	return var
}
func readll() ll {
	var var ll
	fmt.Fscanf(_fin, "%d", &var)
	return var
}

// Function to read an array of integers
func repread(data []int, n int) {
	repi(n) {
		data[i] = readi()
	}
}

// Function to read an array of long long integers
func repread(data []ll, n int) {
	repi(n) {
		data[i] = readll()
	}
}

// Function to read a string, ignoring empty lines
func reads(str []byte, maxsize int) int {
	for {
		if _, err := fmt.Fscanln(_fin, &str); err!= nil {
			break
		}
		if str[0]!= '\n' && str[0]!= '\r' {
			break
		}
	}
	slen := len(str)
	if slen == 0 {
		return 0
	}
	if str[slen-1] == '\n' || str[slen-1] == '\r' {
		str[slen-1] = 0
	}
	return slen
}

// Macros for writing output
func writec(var byte) {
	fmt.Fprint(_fout, string(var))
}
func writecsp(var byte) {
	fmt.Fprint(_fout, string(var), " ")
}
func writecln(var byte) {
	fmt.Fprint(_fout, string(var), "\n")
}
func writei(var int) {
	fmt.Fprint(_fout, var)
}
func writeisp(var int) {
	fmt.Fprint(_fout, var, " ")
}
func writellsp(var ll) {
	fmt.Fprint(_fout, var, " ")
}
func writeiln(var int) {
	fmt.Fprint(_fout, var, "\n")
}
func writellln(var ll) {
	fmt.Fprint(_fout, var, "\n")
}
func writeulln(var ull) {
	fmt.Fprint(_fout, var, "\n")
}
func writefln(var float64) {
	fmt.Fprint(_fout, var, "\n")
}
func writes(str []byte) {
	fmt.Fprint(_fout, string(str))
}
func writesp() {
	fmt.Fprint(_fout, " ")
}
func writeln() {
	fmt.Fprint(_fout, "\n")
}

// Macro to check if a number is even
func iseven(x int) int {
	if x&1 == 0 {
		return 1
	}
	return 0
}

// Macro to run local tests with a specified input file
func RUN_LOCAL(testfilename string) {
	_fin = bufio.NewReader(os.Stdin)
	_fout = bufio.NewWriter(os.Stdout)
}

// Macros for swapping values
func swap(a int, b int) {
	a, b = b, a
}
func swapxor(a int, b int) {
	a ^= b
	b ^= a
	a ^= b
}

// Macro for sorting an array
func sort(data []int, n int) {
	sort.Ints(data)
}

// Macro for modular arithmetic
func mod(a int, b int) int {
	if b == 0 {
		return 0
	}
	if a == 0 {
		return 0
	}
	if a > 0 {
		return a % b
	}
	return b + a % b
}

// Function to compute the greatest common divisor (GCD)
func gcd(a ll, b ll) ll {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to reverse an array of integers
func reversei(data []int, n int) {
	k := n >> 1
	repi(k) {
		data[i], data[n-i-1] = data[n-i-1], data[i]
	}
}

// Function for binary search in a sorted array
func bsearch(val int, data []int, n int) int {
	if data[0] > val {
		return -1
	}
	if data[n-1] < val {
		return n
	}
	l := 0
	r := n - 1
	for {
		mid := (l + r + 1) >> 1
		if data[mid] <= val {
			l = mid
		} else {
			r = mid - 1
		}
		if l == r {
			break
		}
	}
	if data[r]!= val {
		r++
	}
	return r
}

// Macro to define a dynamic array structure
func _Vec(type_ int, name string) {
	type vec struct {
		data []type_
		size int
		n    int
	}
	var t vec
	func init(t *vec, size int) {
		t.data = make([]type_, size)
		t.size = size
		t.n = 0
	}
	func resize(t *vec) {
		ns := t.size * 1.2
		t.data = append(t.data, make([]type_, ns-t.size)...)
		t.size = ns
	}
	func add(t *vec, val type_) {
		if t.n >= t.size {
			resize(t)
		}
		t.data[t.n] = val
		t.n++
	}
	func free(t *vec) {
		t.data = nil
	}
}

// Define dynamic array structures for integers, long longs, and strings
_Vec(int, Veci)
_Vec(ll, Vecll)
_Vec(byte, Vecs)

// Macro to check if two arrays are palindromes
func _ispal(type_ int, name string) int {
	func ispali(a []type_, b []type_, n int) int {
		repi(n) {
			if a[i]!= b[n-i-1] {
				return 0
			}
		}
		return 1
	}
}
_ispal(int, ispali)
_ispal(byte, ispalc)

// Macro to define a pair structure and comparison functions
func _Pair(type_ int, name string) {
	type pair struct {
		x type_
		y type_
	}
	var t pair
	func cmp(a *pair, b *pair) int {
		if a.x == b.x {
			if a.y < b.y {
				return -1
			}
			return 1
		}
		if a.x < b.x {
			return -1
		}
		return 1
	}
	func sort(d []pair, n int) {
		sort.Slice(d, func(i, j int) bool {
			return cmp(&d[i], &d[j]) < 0
		})
	}
}
_Pair(int, Pairi)

// Function to compare strings for sorting
func cmp_Str(a *string, b *string) int {
	return strings.Compare(*a, *b)
}

// Function to sort an array of strings
func sort_Str(str []string, n int) {
	sort.Slice(str, func(i, j int) bool {
		return cmp_Str(&str[i], &str[j]) < 0
	})
}

// Function to compute modular exponentiation
func expmod(x ll, n ll, m ll) ll {
	ans := 1
	for ; n > 0; n >>= 1 {
		if n&1 == 1 {
			ans = (ans * x) % m
		}
		x = (x * x) % m
	}
	return ans
}

// Function to compute combinations modulo m
func combmod(n ll, k ll, m ll) ll {
	ret := 1
	div := 1
	for i := 0; i < k; i++ {
		ret = (ret * (n - i)) % m
		div = (div * (i + 1)) % m
	}
	div = expmod(div, m-2, m)
	return (ret * div) % m
}

//------------

func main() {
	// Run local test with specified input file
	RUN_LOCAL("dataabc155A.txt")

	// Read two integers from input
	var a int
	var b int
	fmt.Fscanf(_fin, "%d", &a)
	fmt.Fscanf(_fin, "%d", &b)

	// Output the smaller integer b times
	if a < b {
		repi(b) {
			fmt.Fprint(_fout, a) // Write 'a' b times
		}
		fmt.Fprint(_fout, "\n") // New line after output
	} else {
		repi(a) {
			fmt.Fprint(_fout, b) // Write 'b' a times
		}
		fmt.Fprint(_fout, "\n") // New line after output
	}
}

