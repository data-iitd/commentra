package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader is a wrapper around bufio.Reader.
// It provides convenient read methods without needing to specify the type of
// the variable to read into.
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a FastReader instance.
func NewFastReader(r *bufio.Reader) *FastReader {
	return &FastReader{r: r}
}

// ReadString reads a string.
func (f *FastReader) ReadString() string {
	s, _ := f.r.ReadString('\n')
	return s[:len(s)-1]
}

// ReadInt reads an integer.
func (f *FastReader) ReadInt() int {
	i, _ := strconv.Atoi(f.ReadString())
	return i
}

// ReadInt64 reads an integer.
func (f *FastReader) ReadInt64() int64 {
	i, _ := strconv.ParseInt(f.ReadString(), 10, 64)
	return i
}

// ReadFloat64 reads a float.
func (f *FastReader) ReadFloat64() float64 {
	i, _ := strconv.ParseFloat(f.ReadString(), 64)
	return i
}

// ReadStringSlice reads a string slice.
func (f *FastReader) ReadStringSlice() []string {
	var line string
	var lines []string
	line, _ = f.r.ReadString('\n')
	lines = strings.Split(line[:len(line)-1], " ")
	return lines
}

func main() {
	// Read the dimensions of the grid
	n := fastReader.ReadInt()
	// Read the number of banned cells
	m := fastReader.ReadInt()

	// Initialize sets to keep track of banned rows and columns
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	// Read each banned cell and add it to the appropriate set if it's not on the border
	for i := 0; i < m; i++ {
		r := fastReader.ReadInt()
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c := fastReader.ReadInt()
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	// Calculate the number of cells that can be reached, accounting for banned rows and columns
	answer := (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	// Adjust the answer if the grid size is odd and the center cell is not banned
	if n%2!= 0 {
		mid := (n + 1) / 2
		if!bannedRows[mid] &&!bannedCols[mid] {
			answer--
		}
	}

	// Output the final answer
	fmt.Println(answer)
}

// 