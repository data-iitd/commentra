
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Initialize IO object and handle resources
func main() {
	io, flash := NewIO()
	defer flash()

	// Read input values
	n, t, a := io.ScanInt(), io.ScanFloat64(), io.ScanFloat64()

	// Initialize variables for heights and minimum difference
	heights := io.ScanFloat64s(n)
	minDiff := AbsDiffFloat64(t-heights[0]*0.006, a)
	minIdx := 0

	// Iterate through the remaining heights and find the minimum difference
	for i, h := range heights[1:] {
		// Calculate the difference between the target and the height
		diff := AbsDiffFloat64(t-h*0.006, a)

		// Update minimum difference and index if the current difference is smaller
		if diff < minDiff {
			minDiff = diff
			minIdx = i + 1
		}
	}

	// Print the result
	fmt.Println(minIdx + 1)
}

// Calculate absolute difference between two float64 numbers
func AbsDiffFloat64(n1, n2 float64) float64 {
	return math.Abs(n1 - n2)
}

// Initialize IO object with scanner and writer
type IO struct {
	scanner *bufio.Scanner
	writer  *bufio.Writer
}

// Create new IO object
func NewIO() (*IO, func()) {
	io := &IO{
		scanner: newScanner(),
		writer:  newWriter(),
	}
	return io, func() { io.writer.Flush() }
}

// Initialize scanner with standard input
func newScanner() *bufio.Scanner {
	s := bufio.NewScanner(os.Stdin)
	s.Buffer(make([]byte, 10000000), 10000000)
	s.Split(bufio.ScanWords)
	return s
}

// Initialize writer with standard output
func newWriter() *bufio.Writer {
	return bufio.NewWriter(os.Stdout)
}

// Read a single byte from the scanner
func (io *IO) ScanBytes() []byte {
	if !io.scanner.Scan() {
		panic("scan string failed")
	}
	return io.scanner.Bytes()
}

// Read a single string from the scanner
func (io *IO) ScanString() string {
	if !io.scanner.Scan() {
		panic("scan string failed")
	}
	return io.scanner.Text()
}

// Read multiple strings from the scanner
func (io *IO) ScanStrings(n int) []string {
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		strs[i] = io.ScanString()
	}
	return strs
}

// Read a 2D array of strings from the scanner
func (io *IO) Scan2DStrings(y, x int) [][]string {
	strings := make([][]string, y)
	for i := 0; i < y; i++ {
		strings[i] = io.ScanStrings(x)
	}
	return strings
}

// Read a 2D array of graphs from the scanner
func (io *IO) Scan2DGraph(y int) [][]string {
	strs := make([][]string, y)
	for i := 0; i < y; i++ {
		strs[i] = strings.Split(io.ScanString(), "")
	}
	return strs
}

// Read a single integer from the scanner
func (io *IO) ScanInt() int {
	return int(io.ScanInt64())
}

// Read two integers from the scanner
func (io *IO) ScanInt2() (int, int) {
	return int(io.ScanInt64()), int(io.ScanInt64())
}

// Read three integers from the scanner
func (io *IO) ScanInt3() (int, int, int) {
	return int(io.ScanInt64()), int(io.ScanInt64()), int(io.ScanInt64())
}

// Read four integers from the scanner
func (io *IO) ScanInt4() (int, int, int, int) {
	return int(io.ScanInt64()), int(io.ScanInt64()), int(io.ScanInt64()), int(io.ScanInt64())
}

// Read a slice of integers from the scanner
func (io *IO) ScanInts(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = io.ScanInt()
	}
	return ints
}

// Read a 2D slice of integers from the scanner
func (io *IO) Scan2DInts(y, x int) [][]int {
	ints := make([][]int, y)
	for i := 0; i < y; i++ {
		ints[i] = io.ScanInts(x)
	}
	return ints
}

// Read a single int64 from the scanner
func (io *IO) ScanInt64() int64 {
	i, err := strconv.ParseInt(io.ScanString(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

// Read a single float64 from the scanner
func (io *IO) ScanFloat64() float64 {
	i, _ := strconv.ParseFloat(io.ScanString(), 64)
	return i
}

// Read a slice of float64 from the scanner
func (io *IO) ScanFloat64s(n int) []float64 {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		floats[i] = io.ScanFloat64()
	}
	return floats
}

// Write a single line to the writer
func (io *IO) Println(a ...interface{}) {
	fmt.Fprintln(io.writer, a...)
}

// Flush the writer buffer
func (io *IO) writer.Flush() {}

// Function to handle resource deallocation
func (io *IO) flash() {
	io.scanner.Close()
	io.writer.Flush()
	os.Stdin.Close()
	os.Stdout.Close()
}

// Function to calculate the absolute difference between two float64 numbers
func AbsDiffFloat64(n1, n2 float64) float64 {
	return math.Abs(n1 - n2)
}

