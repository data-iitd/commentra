package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := new(Scanner)

	// Read the number of elements
	n := sc.nextInt()

	// Initialize an array to store the input values
	v := make([]int, 100010)

	// Read n integers from input and store them in the array v
	for i := 0; i < n; i++ {
		v[i] = sc.nextInt()
	}

	// Initialize arrays to count occurrences of values at different positions
	vo := make([]int, 100010) // Odd indexed counts
	ve := make([]int, 100010) // Even indexed counts
	vt := make([]int, 100010) // Total counts

	// Fill the count arrays with zeros
	for i := 0; i < 100010; i++ {
		vo[i] = 0
		ve[i] = 0
		vt[i] = 0
	}

	// Count occurrences of each number in odd and even indexed positions
	for i := 0; i < n; i++ {
		vt[v[i]]++ // Increment total count for the value
		if i%2 == 0 {
			ve[v[i]]++ // Increment even indexed count
		} else {
			vo[v[i]]++ // Increment odd indexed count
		}
	}

	// Sort the count arrays in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(vo)))
	sort.Sort(sort.Reverse(sort.IntSlice(ve)))
	sort.Sort(sort.Reverse(sort.IntSlice(vt)))

	// Initialize the answer variable
	ans := 0

	// Determine the answer based on the counts of the most frequent elements
	if vo[0]+ve[0] == vt[0] {
		// If the most frequent odd and even counts sum to the total count
		ans = min(n-vo[0]-ve[1], n-vo[1]-ve[0])
	} else {
		// Otherwise, calculate the answer based on the most frequent counts
		ans = n - vo[0] - ve[0]
	}

	// Output the final answer
	fmt.Println(ans)

	// Close the scanner to prevent resource leaks
	sc.close()
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Scanner is a struct that contains a reader and a buffer
type Scanner struct {
	reader *bufio.Reader
	buffer []byte
}

// NewScanner returns a new Scanner object
func NewScanner() *Scanner {
	return &Scanner{
		reader: bufio.NewReader(os.Stdin),
		buffer: make([]byte, 0),
	}
}

// nextInt returns the next integer in the input
func (s *Scanner) nextInt() int {
	// Read the next integer from the input
	var n int
	fmt.Fscan(s.reader, &n)

	// Add the integer to the buffer
	s.buffer = append(s.buffer, n)

	// Return the integer
	return n
}

// close closes the scanner and prevents resource leaks
func (s *Scanner) close() {
	s.reader.Reset(nil)
	s.buffer = nil
}

