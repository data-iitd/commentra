package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// getScanner initializes a new scanner for reading from the provided file pointer.
func getScanner(fp *os.File) *bufio.Scanner {
	scanner := bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords) // Set the scanner to split input by words
	scanner.Buffer(make([]byte, 500001), 500000) // Set buffer size for the scanner
	return scanner
}

// getNextString retrieves the next string from the scanner.
func getNextString(scanner *bufio.Scanner) string {
	scanner.Scan() // Read the next token
	return scanner.Text() // Return the scanned text
}

// getNextInt retrieves the next integer from the scanner.
func getNextInt(scanner *bufio.Scanner) int {
	i, _ := strconv.Atoi(getNextString(scanner)) // Convert the next string to an integer
	return i
}

// getNextInt64 retrieves the next int64 from the scanner.
func getNextInt64(scanner *bufio.Scanner) int64 {
	i, _ := strconv.ParseInt(getNextString(scanner), 10, 64) // Convert the next string to int64
	return i
}

// getNextUint64 retrieves the next uint64 from the scanner.
func getNextUint64(scanner *bufio.Scanner) uint64 {
	i, _ := strconv.ParseUint(getNextString(scanner), 10, 64) // Convert the next string to uint64
	return i
}

// getNextFloat64 retrieves the next float64 from the scanner.
func getNextFloat64(scanner *bufio.Scanner) float64 {
	i, _ := strconv.ParseFloat(getNextString(scanner), 64) // Convert the next string to float64
	return i
}

func main() {
	// Determine the input source: either standard input or a file specified as a command-line argument
	fp := os.Stdin
	if len(os.Args) > 1 {
		fp, _ = os.Open(os.Args[1]) // Open the file if an argument is provided
	}
	scanner := getScanner(fp) // Initialize the scanner for the input source
	writer := bufio.NewWriter(os.Stdout) // Create a buffered writer for output

	// Read the number of elements and operations
	n := getNextInt(scanner)
	m := getNextInt(scanner)

	// Initialize the Segment structure
	seg := Segment{}
	seg.init(n) // Initialize the segment with size n

	// Populate the segment with initial values
	for i := 0; i < n; i++ {
		seg.maximize(i, getNextInt(scanner)) // Maximize the segment with the input values
	}

	// Perform m operations to maximize the segment
	for i := 0; i < m; i++ {
		seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1) // Maximize using the top value and half of the last bucket's first element
	}

	// Calculate the final answer by summing up the values in the first bucket
	var ans int64
	for i := 0; i < n; i++ {
		ans += int64(seg.bucket[0][i]) // Accumulate the values
	}

	// Output the final result
	fmt.Fprintln(writer, ans)
	writer.Flush() // Flush the buffered writer to ensure all output is written
}

// Segment structure to hold the segment data and operations
type Segment struct {
	n, h, i, chunk int
	unit           []int
	bucket         [][]int
}

// init initializes the segment structure with the given size n.
func (seg *Segment) init(n int) {
	seg.n = n
	seg.unit = make([]int, 1) // Initialize unit array
	seg.unit[0] = 1
	seg.bucket = make([][]int, 1) // Initialize bucket array
	seg.bucket[0] = make([]int, n)

	chunk := 8 // Define the chunk size
	for i := 0; n > 1; i++ {
		n = (n-1)/chunk + 1 // Reduce n based on the chunk size
		seg.bucket = append(seg.bucket, make([]int, n)) // Append a new bucket
		seg.unit = append(seg.unit, seg.unit[i]*chunk) // Update unit array
	}
	seg.h = len(seg.unit) // Set the height of the segment
	seg.chunk = chunk // Set the chunk size
}

// maximize updates the segment at a given index with a new value.
func (seg *Segment) maximize(index, value int) {
	seg.bucket[0][index] = value // Set the value in the first bucket
	for seg.i = 0; seg.i < seg.h-1; seg.i++ {
		s := index - index%seg.chunk // Calculate the start of the current chunk
		t := s + seg.chunk // Calculate the end of the current chunk
		if t > len(seg.bucket[seg.i]) {
			t = len(seg.bucket[seg.i]) // Adjust end if it exceeds the bucket length
		}
		parent := index / seg.chunk // Determine the parent index
		max := 0 // Initialize max value
		for i := s; i < t; i++ {
			if max < seg.bucket[seg.i][i] {
				max = seg.bucket[seg.i][i] // Find the maximum value in the current chunk
			}
		}
		seg.bucket[seg.i+1][parent] = max // Update the parent bucket with the maximum value
		index /= seg.chunk // Move to the parent index for the next iteration
	}
}

// top retrieves the index of the top value in the segment.
func (seg *Segment) top() int {
	index := 0 // Start from the root index
	for seg.i = seg.h - 2; seg.i >= 0; seg.i-- {
		s := index * seg.chunk // Calculate the start of the current chunk
		t := s + seg.chunk // Calculate the end of the current chunk
		if t > len(seg.bucket[seg.i]) {
			t = len(seg.bucket[seg.i]) // Adjust end if it exceeds the bucket length
		}
		for i := s; i < t; i++ {
			if seg.bucket[seg.i][i] == seg.bucket[seg.i+1][index] {
				index = i // Update index if the value matches the top value
				break
			}
		}
	}

	return index // Return the index of the top value
}
