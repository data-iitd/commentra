package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// FastReader object to read input efficiently
	in := NewFastReader()
	// PrintWriter object to output the result
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the dimensions of the grid
	n := in.nextInt()
	// Read the number of banned cells
	m := in.nextInt()

	// Initialize sets to keep track of banned rows and columns
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	// Read each banned cell and add it to the appropriate set if it's not on the border
	for i := 0; i < m; i++ {
		r := in.nextInt()
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c := in.nextInt()
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	// Calculate the number of cells that can be reached, accounting for banned rows and columns
	answer := (n - 2) * 2
	for row := range bannedRows {
		answer--
	}
	for col := range bannedCols {
		answer--
	}

	// Adjust the answer if the grid size is odd and the center cell is not banned
	if n%2 != 0 {
		mid := (n + 1) / 2
		if !bannedRows[mid] && !bannedCols[mid] {
			answer--
		}
	}

	// Output the final answer
	fmt.Fprintln(out, answer)
}

// FastReader class to read input efficiently
type FastReader struct {
	sc *bufio.Scanner
}

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
