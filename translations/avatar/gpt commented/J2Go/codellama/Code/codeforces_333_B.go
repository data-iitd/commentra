
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader for efficient input reading
type FastReader struct {
	br *bufio.Reader
	st *strings.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{
		br: bufio.NewReader(os.Stdin),
	}
}

func (f *FastReader) ReadString() string {
	str, _ := f.br.ReadString('\n')
	return str
}

func (f *FastReader) ReadInt() int {
	str := f.ReadString()
	i, _ := strconv.Atoi(str)
	return i
}

func (f *FastReader) ReadLong() int64 {
	str := f.ReadString()
	i, _ := strconv.ParseInt(str, 10, 64)
	return i
}

func (f *FastReader) ReadDouble() float64 {
	str := f.ReadString()
	i, _ := strconv.ParseFloat(str, 64)
	return i
}

func (f *FastReader) ReadLine() string {
	str, _ := f.br.ReadString('\n')
	return str
}

func main() {
	// Read the dimensions of the grid
	n := NewFastReader().ReadInt()
	m := NewFastReader().ReadInt()

	// Initialize sets to keep track of banned rows and columns
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	// Read the banned rows and columns
	for i := 0; i < m; i++ {
		r := NewFastReader().ReadInt()
		// Add to bannedRows if the row is within valid range
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c := NewFastReader().ReadInt()
		// Add to bannedCols if the column is within valid range
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	// Calculate the initial answer based on the grid size
	answer := (n - 2) * 2
	// Subtract the number of banned rows and columns from the answer
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	// If n is odd, check the middle row and column
	if n%2 != 0 {
		mid := (n + 1) / 2
		// If the middle row and column are not banned, decrement the answer
		if !bannedRows[mid] && !bannedCols[mid] {
			answer--
		}
	}

	// Output the final answer
	fmt.Println(answer)
}

// 