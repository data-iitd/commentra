package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	scanner := NewScanner(os.Stdin)

	// Read the number of elements N and the number of groups M
	N, _ := strconv.Atoi(scanner.Scan())
	M, _ := strconv.Atoi(scanner.Scan())

	// Create an ArrayList to store bitwise representations for each element
	a := make([]int, N)

	// Initialize the ArrayList with zeros for N elements
	for i := 0; i < N; i++ {
		a[i] = 0
	}

	// Read M groups of integers and update the bitwise representation
	for i := 0; i < M; i++ {
		k, _ := strconv.Atoi(scanner.Scan()) // Read the number of integers in the current group
		for j := 0; j < k; j++ {
			s, _ := strconv.Atoi(scanner.Scan()) // Read the integer
			s--                                  // Convert to zero-based index
			// Update the bitwise representation for the element
			a[s] = a[s] | (1 << i)
		}
	}

	// Read M integers to create a bitmask p
	p := 0
	for i := 0; i < M; i++ {
		x, _ := strconv.Atoi(scanner.Scan()) // Read the integer
		p |= (x << i)                        // Update the bitmask p
	}

	// Initialize a counter for valid combinations
	ans := 0

	// Iterate through all possible subsets of N elements
	for s := 0; s < (1 << N); s++ {
		t := 0 // Initialize a temporary variable to store the XOR result
		for i := 0; i < N; i++ {
			// Check if the i-th element is included in the subset
			if ((s >> i) & 1) == 1 {
				// XOR the current element's bitwise representation
				t ^= a[i]
			}
		}
		// Check if the XOR result matches the bitmask p
		if p == t {
			ans++ // Increment the count of valid combinations
		}
	}

	// Output the total count of valid combinations
	fmt.Println(ans)

	// Close the scanner to free resources
	scanner.Close()
}

// Scanner is a struct that wraps a bufio.Scanner to read input from a file
type Scanner struct {
	*bufio.Scanner
}

// NewScanner returns a new Scanner that reads input from the given file
func NewScanner(file *os.File) *Scanner {
	return &Scanner{Scanner: bufio.NewScanner(file)}
}

// Scan returns the next token from the scanner
func (s *Scanner) Scan() string {
	s.Scan()
	return s.Text()
}

// Close closes the scanner and the underlying file
func (s *Scanner) Close() error {
	if err := s.Scanner.Err(); err != nil {
		return err
	}
	return s.Scanner.Split(bufio.ScanLines)[0].Err()
}

// Split splits the input on newlines
func (s *Scanner) Split(data []byte, atEOF bool) (advance int, token []byte, err error) {
	if atEOF && len(data) == 0 {
		return 0, nil, nil
	}
	if i := strings.IndexByte(string(data), '\n'); i >= 0 {
		// We have a full newline-terminated line.
		return i + 1, data[0:i], nil
	}
	// If we're at EOF, we have a final, non-terminated line. Return it.
	if atEOF {
		return len(data), data, nil
	}
	// Request more data.
	return 0, nil, nil
}

