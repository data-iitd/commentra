// Package main is the entry point of the program
package main

import (
	"bufio" // Import bufio package for reading and writing lines
	"fmt"   // Import fmt package for formatted I/O
	"os"    // Import os package for file I/O
	"strconv" // Import strconv package for converting strings to numeric types
)

// getScanner function returns a bufio.Scanner instance configured for reading words
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000) // Buffer size for efficient reading
	return scanner
}

// getNextString function returns the next word as a string
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// getNextInt function returns the next integer from the scanner
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner))
	return i
}

// getNextInt64 function returns the next 64-bit integer from the scanner
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64)
	return i
}

// getNextUint64 function returns the next 64-bit unsigned integer from the scanner
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64)
	return i
}

// getNextFloat64 function returns the next 64-bit floating-point number from the scanner
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64)
	return i
}

// main function is the entry point of the program
func main() {
	// Open the standard input file if a command-line argument is provided
	fp := os.Stdin
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1])
	}

	// Initialize a bufio.Writer for formatted output
	writer := bufio.NewWriter(os.Stdout)

	// Read the first two integers from the input
	n := getNextInt(getScanner(fp))
	m := getNextInt(getScanner(fp))

	// Initialize the Segment struct with the given size n
	seg := Segment{}
	seg.init(n)

	// Process the input data by maximizing the segments
	for i := 0; i < n; i++ {
		seg.maximize(i, getNextInt(getScanner(fp)))
	}
	for i := 0; i < m; i++ {
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1)
	}

	// Calculate the answer and print it to the output
	var ans int64
	for i := 0; i < n; i++ {
		ans += int64(seg.bucket[0][i])
	}

	// Print the answer to the output
	fmt.Fprintln(writer, ans)

	// Flush the writer buffer to ensure all data is written
	writer.Flush()
}

// Segment type represents a segment tree data structure
type Segment struct {
	n, h, i, chunk int
	unit           []int
	bucket         [][]int
}

// init function initializes the Segment struct with the given size n
func (seg *Segment) init(n int) {
	seg.n = n
	seg.unit = make([]int, 1)
	seg.unit[0] = 1
	seg.bucket = make([][]int, 1)
	seg.bucket[0] = make([]int, n)

	// Calculate the chunk size for the segment tree
	chunk := 8
	for i := 0; n > 1; i++ {
		n = (n-1)/chunk + 1
		seg.bucket = append(seg.bucket, make([]int, n))
		seg.unit = append(seg.unit, seg.unit[i]*chunk)
	}
	seg.h = len(seg.unit)
	seg.chunk = chunk
}

// maximize function updates the segment tree with the given index and value
func (seg *Segment) maximize(index, value int) {
	// Update the leaf node with the given index and value
	seg.bucket[0][index] = value

	// Propagate the update to the parent nodes
	for seg.i = 0; seg.i < seg.h-1; seg.i++ {
		s := index - index%seg.chunk
		t := s + seg.chunk
		if t > len(seg.bucket[seg.i]) {
			t = len(seg.bucket[seg.i])
		}
		parent := index / seg.chunk
		max := 0
		for i := s; i < t; i++ {
			if max < seg.bucket[seg.i][i] {
				max = seg.bucket[seg.i][i]
			}
		}
		seg.bucket[seg.i+1][parent] = max
		index /= seg.chunk
	}
}

// top function returns the index of the maximum value in the current segment
func (seg *Segment) top() int {
	index := 0
	for seg.i = seg.h - 2; seg.i >= 0; seg.i-- {
		s := index * seg.chunk
		t := s + seg.chunk
		if t > len(seg.bucket[seg.i]) {
			t = len(seg.bucket[seg.i])
		}
		for i := s; i < t; i++ {
			if seg.bucket[seg.i][i] == seg.bucket[seg.i+1][index] {
				index = i
				break
			}
		}
	}

	return index
}
