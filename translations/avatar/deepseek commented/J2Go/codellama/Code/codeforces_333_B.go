
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader object to read input efficiently
type FastReader struct {
	br *bufio.Reader
	st *strings.Reader
}

// NewFastReader creates a new FastReader object
func NewFastReader() *FastReader {
	return &FastReader{
		br: bufio.NewReader(os.Stdin),
	}
}

// ReadString reads a string from the input
func (f *FastReader) ReadString() string {
	if f.st == nil || !f.st.Scan() {
		line, _, err := f.br.ReadLine()
		if err != nil {
			panic(err)
		}
		f.st = strings.NewReader(string(line))
	}
	return f.st.Text()
}

// ReadInt reads an integer from the input
func (f *FastReader) ReadInt() int {
	return int(f.ReadInt64())
}

// ReadInt64 reads an integer from the input
func (f *FastReader) ReadInt64() int64 {
	return int64(f.ReadInt64AsFloat64())
}

// ReadInt64AsFloat64 reads an integer from the input
func (f *FastReader) ReadInt64AsFloat64() float64 {
	str := f.ReadString()
	val, err := strconv.ParseFloat(str, 64)
	if err != nil {
		panic(err)
	}
	return val
}

// ReadFloat64 reads a float64 from the input
func (f *FastReader) ReadFloat64() float64 {
	str := f.ReadString()
	val, err := strconv.ParseFloat(str, 64)
	if err != nil {
		panic(err)
	}
	return val
}

// ReadLine reads a line from the input
func (f *FastReader) ReadLine() string {
	str, _, err := f.br.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}

// ReadLines reads multiple lines from the input
func (f *FastReader) ReadLines() []string {
	var lines []string
	for {
		str, _, err := f.br.ReadLine()
		if err != nil {
			panic(err)
		}
		if len(str) == 0 {
			break
		}
		lines = append(lines, string(str))
	}
	return lines
}

// PrintWriter object to output the result
type PrintWriter struct {
	writer *bufio.Writer
}

// NewPrintWriter creates a new PrintWriter object
func NewPrintWriter() *PrintWriter {
	return &PrintWriter{
		writer: bufio.NewWriter(os.Stdout),
	}
}

// Println prints a line to the output
func (p *PrintWriter) Println(a ...interface{}) {
	fmt.Fprintln(p.writer, a...)
}

// Printf prints a formatted string to the output
func (p *PrintWriter) Printf(format string, a ...interface{}) {
	fmt.Fprintf(p.writer, format, a...)
}

// Close closes the output stream
func (p *PrintWriter) Close() {
	p.writer.Flush()
}

// Main function
func main() {
	// Read the dimensions of the grid
	n := int(NewFastReader().ReadInt64())
	// Read the number of banned cells
	m := int(NewFastReader().ReadInt64())

	// Initialize sets to keep track of banned rows and columns
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	// Read each banned cell and add it to the appropriate set if it's not on the border
	for i := 0; i < m; i++ {
		r := int(NewFastReader().ReadInt64())
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c := int(NewFastReader().ReadInt64())
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	// Calculate the number of cells that can be reached, accounting for banned rows and columns
	answer := (n - 2) * 2
	for r := range bannedRows {
		answer--
	}
	for c := range bannedCols {
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
	NewPrintWriter().Println(answer)
	// Close the output stream
	NewPrintWriter().Close()
}

// 