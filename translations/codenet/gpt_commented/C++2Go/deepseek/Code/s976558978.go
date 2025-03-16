package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

// Mathematical constants and limits
const (
	PI = 3.141592653589793238462643383279502884197169399375105820974
	ten5p1 = 100001
	ten6p1 = 1000001
	ten8p1 = 100000001
	ten9p1 = 1000000001
)

// Type definitions for convenience
type (
	uint = uint32
	ll = int64
	ull = uint64
)

// Macros for loop iterations
func rep(var, n int) {
	for var = 0; var < n; var++ {
	}
}

func repi(n int) {
	rep(i, n)
}

func repj(n int) {
	rep(j, n)
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
func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func _max(a, b int) int {
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

func zeroll(data []int64, n int) {
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
	fmt.Fscanf(os.Stdin, "%c", &var)
	return var
}

func readi() int {
	var var int
	fmt.Fscanf(os.Stdin, "%d", &var)
	return var
}

func readll() int64 {
	var var int64
	fmt.Fscanf(os.Stdin, "%lld", &var)
	return var
}

// Function to read an array of integers
func repread(data []int) {
	for i := 0; i < len(data); i++ {
		data[i] = readi()
	}
}

// Function to read an array of long long integers
func repread(data []int64) {
	for i := 0; i < len(data); i++ {
		data[i] = readll()
	}
}

// Function to read a string, ignoring empty lines
func reads(str []byte, maxsize int) int {
	reader := bufio.NewReader(os.Stdin)
	for {
		line, _ := reader.ReadString('\n')
		line = strings.TrimRight(line, "\r\n")
		if len(line) > 0 {
			copy(str, line)
			return len(line)
		}
	}
}

// Macros for writing output
func writec(var byte) {
	fmt.Fprintf(os.Stdout, "%c", var)
}

func writecsp(var byte) {
	fmt.Fprintf(os.Stdout, "%c ", var)
}

func writecln(var byte) {
	fmt.Fprintf(os.Stdout, "%c\n", var)
}

func writei(var int) {
	fmt.Fprintf(os.Stdout, "%d", var)
}

func writeisp(var int) {
	fmt.Fprintf(os.Stdout, "%d ", var)
}

func writellsp(var int64) {
	fmt.Fprintf(os.Stdout, "%lld ", var)
}

func writeiln(var int) {
	fmt.Fprintf(os.Stdout, "%d\n", var)
}

func writellln(var int64) {
	fmt.Fprintf(os.Stdout, "%lld\n", var)
}

func writeulln(var uint64) {
	fmt.Fprintf(os.Stdout, "%llu\n", var)
}

func writefln(var float64) {
	fmt.Fprintf(os.Stdout, "%f\n", var)
}

func writes(str string) {
	fmt.Fprintf(os.Stdout, "%s", str)
}

func writesp() {
	fmt.Fprintf(os.Stdout, " ")
}

func writeln() {
	fmt.Fprintf(os.Stdout, "\n")
}

// Macro to check if a number is even
func iseven(x int) bool {
	return x&1 == 0
}

// Macro to run local tests with a specified input file
func RUN_LOCAL(testfilename string) {
	if file, err := os.Open(testfilename); err == nil {
		os.Stdin = file
	}
}

// Macros for swapping values
func swap(a, b *int) {
	*a, *b = *b, *a
}

func swapxor(a, b *int) {
	*a ^= *b
	*b ^= *a
	*a ^= *b
}

// Macro for sorting an array
func sort(data []int) {
	sort.Ints(data)
}

// Macro for modular arithmetic
func mod(a, b int) int {
	if b == 0 {
		return 0
	}
	if a == 0 {
		return 0
	}
	return a % b
}

// Function to compute the greatest common divisor (GCD)
func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a % b)
}

// Function to reverse an array of integers
func reversei(data []int, n int) {
	for i := 0; i < n/2; i++ {
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
	l, r := 0, n-1
	for l < r {
		mid := (l + r + 1) / 2
		if data[mid] <= val {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if data[r] != val {
		r++
	}
	return r
}

// Macro to define a dynamic array structure
type Veci struct {
	data []int
	size int
	n    int
}

func initVeci(t *Veci, size int) {
	t.data = make([]int, size)
	t.size = size
	t.n = 0
}

func resizeVeci(t *Veci) {
	ns := int(float32(t.size) * 1.2)
	t.data = append(t.data, make([]int, ns-t.size)...)
	t.size = ns
}

func addVeci(t *Veci, val int) {
	if t.n >= t.size {
		resizeVeci(t)
	}
	t.data[t.n] = val
	t.n++
}

func freeVeci(t *Veci) {
	t.data = nil
}

type Vecll struct {
	data []int64
	size int
	n    int
}

func initVecll(t *Vecll, size int) {
	t.data = make([]int64, size)
	t.size = size
	t.n = 0
}

func resizeVecll(t *Vecll) {
	ns := int(float32(t.size) * 1.2)
	t.data = append(t.data, make([]int64, ns-t.size)...)
	t.size = ns
}

func addVecll(t *Vecll, val int64) {
	if t.n >= t.size {
		resizeVecll(t)
	}
	t.data[t.n] = val
	t.n++
}

func freeVecll(t *Vecll) {
	t.data = nil
}

type Vecs struct {
	data []string
	size int
	n    int
}

func initVecs(t *Vecs, size int) {
	t.data = make([]string, size)
	t.size = size
	t.n = 0
}

func resizeVecs(t *Vecs) {
	ns := int(float32(t.size) * 1.2)
	t.data = append(t.data, make([]string, ns-t.size)...)
	t.size = ns
}

func addVecs(t *Vecs, val string) {
	if t.n >= t.size {
		resizeVecs(t)
	}
	t.data[t.n] = val
	t.n++
}

func freeVecs(t *Vecs) {
	t.data = nil
}

// Macro to check if two arrays are palindromes
func ispali(a, b []int, n int) bool {
	for i := 0; i < n; i++ {
		if a[i] != b[n-i-1] {
			return false
		}
	}
	return true
}

func ispalc(a, b []byte, n int) bool {
	for i := 0; i < n; i++ {
		if a[i] != b[n-i-1] {
			return false
		}
	}
	return true
}

// Macro to define a pair structure and comparison functions
type Pairi struct {
	x, y int
}

func cmpPairi(a, b *Pairi) int {
	if a.x == b.x {
		if a.y < b.y {
			return -1
		} else {
			return 1
		}
	}
	if a.x < b.x {
		return -1
	} else {
		return 1
	}
}

func sortPairi(d []Pairi, n int) {
	sort.Slice(d, func(i, j int) bool {
		return cmpPairi(&d[i], &d[j]) < 0
	})
}

// Function to compare strings for sorting
func cmpStr(a, b *string) int {
	return strings.Compare(*a, *b)
}

func sortStr(str []string) {
	sort.Slice(str, func(i, j int) bool {
		return cmpStr(&str[i], &str[j]) < 0
	})
}

// Function to compute modular exponentiation
func expmod(x, n, m int64) int64 {
	ans := int64(1)
	for ; n > 0; n >>= 1 {
		if n&1 == 1 {
			ans = (ans * x) % m
		}
		x = (x * x) % m
	}
	return ans
}

// Function to compute combinations modulo m
func combmod(n, k, m int64) int64 {
	ret := int64(1)
	div := int64(1)
	for i := int64(0); i < k; i++ {
		ret = (ret * (n - i) % m) % m
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
	a := readi()
	b := readi()

	// Output the smaller integer b times
	if a < b {
		for i := 0; i < b; i++ {
			writei(a)
		}
		writeln()
	} else {
		for i := 0; i < a; i++ {
			writei(b)
		}
		writeln()
	}
}

