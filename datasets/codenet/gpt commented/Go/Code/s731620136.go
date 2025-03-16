// +build ignore
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// Scanner struct for handling input
type Scanner struct {
	sc *bufio.Scanner
}

// NewScanner initializes a new Scanner for reading input
func NewScanner() *Scanner {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords) // Split input by words
	sc.Buffer(make([]byte, 10240), int(1e+9)) // Set buffer size
	return &Scanner{sc}
}

// nextStr reads the next string from input
func (s *Scanner) nextStr() string {
	s.sc.Scan()
	return s.sc.Text()
}

// nextInt reads the next integer from input
func (s *Scanner) nextInt() int {
	i, e := strconv.Atoi(s.nextStr())
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return i
}

// nextFloat reads the next float from input
func (s *Scanner) nextFloat() float64 {
	f, e := strconv.ParseFloat(s.nextStr(), 64)
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return f
}

// nextRuneSlice reads the next string and converts it to a byte slice
func (s *Scanner) nextRuneSlice() []byte {
	return []byte(s.nextStr())
}

// nextIntSlice reads a slice of integers from input
func (s *Scanner) nextIntSlice(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = s.nextInt() // Fill the slice with integers
	}
	return res
}

// nextFloatSlice reads a slice of floats from input
func (s *Scanner) nextFloatSlice(n int) []float64 {
	res := make([]float64, n)
	for i := 0; i < n; i++ {
		res[i] = s.nextFloat() // Fill the slice with floats
	}
	return res
}

// run processes the input and produces output
func run(input io.Reader, output io.Writer) int {
	sc := NewScanner() // Create a new scanner instance
	N := sc.nextInt()  // Read the number of elements
	S := sc.nextStr()  // Read the string of colors

	// Handle case where there are no elements
	if N == 0 {
		return 0
	}

	// If there are fewer than 4 elements, output 0
	if N < 4 {
		fmt.Println(0)
		return 0
	}

	// Count occurrences of each color
	var nr, nb, ng int
	for _, c := range S {
		if c == 'R' {
			nr++
		}
		if c == 'B' {
			nb++
		}
		if c == 'G' {
			ng++
		}
	}

	same := 0 // Counter for same color combinations

	// Iterate through possible combinations of indices
	for a := 1; a < N; a++ {
		i := 0
		j := 1 * a
		k := 2 * a
		if k >= N {
			break // Exit if index exceeds string length
		}
		for k < N {
			// Check if the colors at the indices are different
			if S[i] != S[j] && S[i] != S[k] && S[j] != S[k] {
				same++ // Increment same color combination counter
			}
			i += 1 // Move to the next index
			j += 1
			k += 1
		}
	}

	// Calculate total combinations of different colors
	tot := nr * nb * ng

	// Output the result by subtracting same combinations from total
	fmt.Println(tot - same)

	return 0 // Return success
}

// main function to execute the program
func main() {
	os.Exit(run(os.Stdin, os.Stdout)) // Run the program and exit
}
