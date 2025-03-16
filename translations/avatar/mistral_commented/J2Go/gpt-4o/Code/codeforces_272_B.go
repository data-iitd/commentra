package main

import (
	"bufio" // Import bufio for buffered I/O
	"fmt"   // Import fmt for formatted I/O
	"os"    // Import os for standard I/O
)

// FastReader struct for efficient input reading
type FastReader struct {
	scanner *bufio.Scanner
}

// NewFastReader initializes a new FastReader
func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)}
}

// Next reads the next token as a string
func (fr *FastReader) Next() string {
	fr.scanner.Scan() // Read the next line
	return fr.scanner.Text()
}

// NextInt reads the next token as an integer
func (fr *FastReader) NextInt() int {
	var num int
	fmt.Sscanf(fr.Next(), "%d", &num) // Parse the integer from the string
	return num
}

// Rec calculates the index of a number based on the number of set bits in its binary representation
func Rec(x int64) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if (x & (1 << k)) != 0 { // If the k-th bit is set
			answer++ // Increment the answer
		}
	}
	return answer
}

func main() {
	fr := NewFastReader() // Initialize FastReader

	n := fr.NextInt() // Read the number of test cases

	// Initialize an array 'a' to store the frequency of each number
	a := make([]int, 33)

	// Read each test case and update the frequency of the number in the array 'a'
	for i := 0; i < n; i++ {
		num := fr.NextInt() // Read a number
		index := Rec(int64(num)) // Get the index of the number in the array 'a'
		a[index]++ // Increment the frequency of the number in the array 'a'
	}

	// Calculate the answer
	answer := 0.0
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]-1)) / 2.0 * float64(a[i]-1) // Calculate the sum of squares of numbers up to the current number
		answer += summ // Add the sum to the answer
	}

	fmt.Println(int64(answer)) // Print the answer as a long integer
}

// <END-OF-CODE>
