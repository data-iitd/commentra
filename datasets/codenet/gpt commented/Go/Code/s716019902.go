package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// Define constants for modulo operation and factorial limit
const mod = 998244353
const facNum = 300001

func main() {
	// Initialize a new scanner for reading input
	sc := newScanner(os.Stdin)
	// Read an integer N from input
	N := sc.i()
	sum := 0
	
	// Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for i := 1; i <= N; i++ {
		if i%3 == 0 || i%5 == 0 {
			continue // Skip numbers divisible by 3 or 5
		}
		sum += i // Add the number to the sum
	}
	
	// Output the final sum
	fmt.Println(sum)
}

// scanner struct for handling input
type scanner struct {
	sc *bufio.Scanner
}

// newScanner initializes a new scanner with a specified input reader
func newScanner(input io.Reader) *scanner {
	sc := bufio.NewScanner(input)
	sc.Split(bufio.ScanWords) // Split input by words
	sc.Buffer(make([]byte, 1024), int(1e+9)) // Set buffer size
	return &scanner{sc}
}

// s reads a string from the scanner
func (s *scanner) s() string {
	s.sc.Scan()
	return s.sc.Text()
}

// i reads an integer from the scanner
func (s *scanner) i() int {
	i, e := strconv.Atoi(s.s()) // Convert string to integer
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return i
}

// f reads a float64 from the scanner
func (s *scanner) f() float64 {
	f, e := strconv.ParseFloat(s.s(), 64) // Convert string to float64
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return f
}

// bs reads a byte slice from the scanner
func (s *scanner) bs() []byte {
	return []byte(s.s()) // Convert string to byte slice
}

// is reads n integers from the scanner into a slice
func (s *scanner) is(n int) []int {
	res := make([]int, n) // Create a slice of integers
	for i := 0; i < n; i++ {
		res[i] = s.i() // Read each integer
	}
	return res
}

// fs reads n float64 values from the scanner into a slice
func (s *scanner) fs(n int) []float64 {
	res := make([]float64, n) // Create a slice of float64
	for i := 0; i < n; i++ {
		res[i] = s.f() // Read each float64
	}
	return res
}

// Pow calculates a^n under modulo
func Pow(a, n int) int {
	ans := 1
	for n > 0 {
		if (n & 1) == 1 {
			ans = ans * a % mod // Multiply by a if n is odd
		}
		a = a * a % mod // Square a
		n = n >> 1 // Right shift n
	}
	return ans // Return the result
}

// Gcd calculates the greatest common divisor of a and b
func Gcd(a, b int) int {
	if a < b {
		return Gcd(b, a) // Ensure a is greater than b
	}
	for b != 0 {
		a, b = b, a%b // Apply Euclidean algorithm
	}
	return a // Return the GCD
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a // Return a if it's smaller
	}
	return b // Otherwise return b
}

// combination calculates n choose k using precomputed factorials
func combination(n, k int, fac, ifac []int) int {
	if n < k || n < 0 {
		return 0 // Return 0 if invalid
	}
	if k == 0 {
		return 1 // Return 1 if k is 0
	}
	// Calculate combination using factorials
	ans := ifac[k] * ifac[n-k] % mod
	return ans * fac[n] % mod
}

// factorial precomputes factorials and their modular inverses
func factorial() (fac []int, ifac []int) {
	fac = make([]int, facNum) // Create a slice for factorials
	fac[0] = 1
	ifac = make([]int, facNum) // Create a slice for inverse factorials
	ifac[0] = 1
	for i := 1; i < facNum; i++ {
		fac[i] = fac[i-1] * i % mod // Compute factorial
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod // Compute inverse factorial using Fermat's little theorem
	}
	return
}

// lowerBound finds the index of the first element in a sorted slice that is not less than v
func lowerBound(vs []int, v int) (index int) {
	n := len(vs) / 2 // Initialize mid index
	m := len(vs) // Length of the slice
	for m != n {
		if vs[n] < v {
			n = (m-n+1)/2 + n // Move to the right half
		} else {
			m = n // Move to the left half
			n = n / 2 // Update mid index
		}
	}
	return n // Return the found index
}

// IntSlice creates a slice of integers initialized to a specific value
func IntSlice(n, init int) []int {
	r := make([]int, n) // Create a slice of length n
	for i := range r {
		r[i] = init // Initialize each element
	}
	return r // Return the initialized slice
}
