package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// FastReader for efficient input reading
	in := NewFastReader()
	// Read the dimensions of the grid
	n := in.nextInt()
	m := in.nextInt()
	
	// Initialize sets to keep track of banned rows and columns
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)
	
	// Read the banned rows and columns
	for i := 0; i < m; i++ {
		r := in.nextInt()
		// Add to bannedRows if the row is within valid range
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c := in.nextInt()
		// Add to bannedCols if the column is within valid range
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}
	
	// Calculate the initial answer based on the grid size
	answer := (n - 2) * 2
	// Subtract the number of banned rows and columns from the answer
	for r := range bannedRows {
		answer--
	}
	for c := range bannedCols {
		answer--
	}
	
	// If n is odd, check the middle row and column
	if n % 2 != 0 {
		mid := (n + 1) / 2
		// If the middle row and column are not banned, decrement the answer
		if !bannedRows[mid] && !bannedCols[mid] {
			answer--
		}
	}
	
	// Output the final answer
	fmt.Println(answer)
}

// FastReader struct for efficient input handling
type FastReader struct {
	sc *bufio.Scanner
}

// NewFastReader initializes a new FastReader
func NewFastReader() *FastReader {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return &FastReader{sc: sc}
}

// Method to read the next token
func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

// Method to read the next integer
func (r *FastReader) nextInt() int {
	num, _ := strconv.Atoi(r.next())
	return num
}

// Method to read the next long
func (r *FastReader) nextLong() int64 {
	num, _ := strconv.ParseInt(r.next(), 10, 64)
	return num
}

// Method to read the next double
func (r *FastReader) nextDouble() float64 {
	num, _ := strconv.ParseFloat(r.next(), 64)
	return num
}

// Method to read the next line
func (r *FastReader) nextLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}
