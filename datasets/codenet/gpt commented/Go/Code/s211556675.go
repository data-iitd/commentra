package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// I/O
// Scanner struct to facilitate reading input from standard input
type Scanner struct {
	sc *bufio.Scanner
}

// NewScanner initializes a new Scanner instance
func NewScanner() *Scanner {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords) // Split input by words
	sc.Buffer(make([]byte, 1024), int(1e+9)) // Set buffer size
	return &Scanner{sc}
}

// nextStr reads the next string from input
func (s *Scanner) nextStr() string {
	s.sc.Scan()
	return s.sc.Text()
}

// nextInt reads the next integer from input
func (s *Scanner) nextInt() int {
	i, e := strconv.Atoi(s.nextStr()) // Convert string to integer
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return i
}

// nextFloat reads the next float from input
func (s *Scanner) nextFloat() float64 {
	f, e := strconv.ParseFloat(s.nextStr(), 64) // Convert string to float
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return f
}

// nextRuneSlice reads the next string and converts it to a slice of runes
func (s *Scanner) nextRuneSlice() []rune {
	return []rune(s.nextStr())
}

// nextIntSlice reads n integers from input and returns them as a slice
func (s *Scanner) nextIntSlice(n int) []int {
	res := make([]int, n) // Create a slice to hold the integers
	for i := 0; i < n; i++ {
		res[i] = s.nextInt() // Read each integer
	}
	return res
}

// nextFloatSlice reads n floats from input and returns them as a slice
func (s *Scanner) nextFloatSlice(n int) []float64 {
	res := make([]float64, n) // Create a slice to hold the floats
	for i := 0; i < n; i++ {
		res[i] = s.nextFloat() // Read each float
	}
	return res
}

// Arithmetic functions

// max returns the maximum value from a list of integers
func max(nums ...int) int {
	m := nums[0] // Initialize max with the first element
	for _, i := range nums {
		if m < i {
			m = i // Update max if a larger value is found
		}
	}
	return m
}

// min returns the minimum value from a list of integers
func min(nums ...int) int {
	m := nums[0] // Initialize min with the first element
	for _, i := range nums {
		if m > i {
			m = i // Update min if a smaller value is found
		}
	}
	return m
}

// abs returns the absolute value of an integer
func abs(x int) int {
	if x > 0 {
		return x // Return x if positive
	}
	return -x // Return -x if negative
}

// pow computes x raised to the power of y
func pow(x, y int) int {
	res := 1 // Initialize result
	for i := 0; i < y; i++ {
		res *= x // Multiply res by x, y times
	}
	return res
}

// Sort related types and methods

// Val struct to hold a value and its associated ID
type Val struct {
	id, num int
}

// ByNum is a type that implements sort.Interface based on the num field
type ByNum []Val

// Len returns the number of elements in the collection
func (a ByNum) Len() int { return len(a) }

// Less reports whether the element with index i should sort before the element with index j
func (a ByNum) Less(i, j int) bool { return a[i].num < a[j].num }

// Swap exchanges the elements with indexes i and j
func (a ByNum) Swap(i, j int) { a[i], a[j] = a[j], a[i] }

// Main function
func main() {
	sc := NewScanner() // Create a new scanner for input
	wtr := bufio.NewWriter(os.Stdout) // Create a buffered writer for output

	// Read four integers from input
	A, B, C, K := sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()

	// Determine the maximum value among A, B, and C
	ma := max(A, B, C)
	rest := 0 // Initialize the rest variable to hold the sum of the other two values

	// Calculate the sum of the two smaller values
	if ma == A {
		rest += B + C
	} else if ma == B {
		rest += A + C
	} else {
		rest += A + B
	}

	// Double the maximum value K times
	for i := 1; i <= K; i++ {
		ma *= 2
	}

	// Output the final result: doubled max value plus the sum of the other two
	fmt.Fprintln(wtr, ma+rest)
	wtr.Flush() // Ensure all buffered data is written to output
}
