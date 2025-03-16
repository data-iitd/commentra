package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize input/output handling
	io, flash := NewIO()
	defer flash() // Ensure the writer is flushed before exiting

	// Read the number of heights, target temperature, and actual temperature
	n, t, a := io.ScanInt(), io.ScanFloat64(), io.ScanFloat64()
	// Read the heights as a slice of float64
	heights := io.ScanFloat64s(n)

	// Initialize minimum difference and index for tracking the closest height
	minDiff := AbsDiffFloat64(t-heights[0]*0.006, a)
	minIdx := 0

	// Iterate through the heights to find the one with the minimum temperature difference
	for i, h := range heights[1:] {
		diff := AbsDiffFloat64(t-h*0.006, a)
		if diff < minDiff {
			minDiff = diff
			minIdx = i + 1 // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	fmt.Println(minIdx + 1)
}

// AbsDiffFloat64 calculates the absolute difference between two float64 numbers
func AbsDiffFloat64(n1, n2 float64) float64 {
	return math.Abs(n1 - n2)
}

// IO struct for handling input and output operations
type IO struct {
	scanner *bufio.Scanner
	writer  *bufio.Writer
}

// NewIO initializes a new IO instance with a scanner and writer
func NewIO() (*IO, func()) {
	io := &IO{
		scanner: newScanner(),
		writer:  newWriter(),
	}
	return io, func() { io.writer.Flush() } // Return a function to flush the writer
}

// newScanner creates and configures a new bufio.Scanner
func newScanner() *bufio.Scanner {
	s := bufio.NewScanner(os.Stdin)
	s.Buffer(make([]byte, 10000000), 10000000) // Set buffer size for the scanner
	s.Split(bufio.ScanWords) // Split input by words
	return s
}

// newWriter creates a new bufio.Writer for output
func newWriter() *bufio.Writer {
	return bufio.NewWriter(os.Stdout) // Write output to standard output
}

// ScanBytes scans and returns a byte slice from input
func (io *IO) ScanBytes() []byte {
	if !io.scanner.Scan() {
		panic("scan string failed") // Panic if scanning fails
	}
	return io.scanner.Bytes() // Return scanned bytes
}

// ScanString scans and returns a string from input
func (io *IO) ScanString() string {
	if !io.scanner.Scan() {
		panic("scan string failed") // Panic if scanning fails
	}
	return io.scanner.Text() // Return scanned string
}

// ScanStrings scans and returns a slice of strings from input
func (io *IO) ScanStrings(n int) []string {
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		strs[i] = io.ScanString() // Scan each string
	}
	return strs // Return the slice of strings
}

// Scan2DStrings scans and returns a 2D slice of strings from input
func (io *IO) Scan2DStrings(y, x int) [][]string {
	strings := make([][]string, y)
	for i := 0; i < y; i++ {
		strings[i] = io.ScanStrings(x) // Scan each row of strings
	}
	return strings // Return the 2D slice of strings
}

// Scan2DGraph scans and returns a 2D slice of strings representing a graph
func (io *IO) Scan2DGraph(y int) [][]string {
	strs := make([][]string, y)
	for i := 0; i < y; i++ {
		strs[i] = strings.Split(io.ScanString(), "") // Split each line into characters
	}
	return strs // Return the 2D slice of characters
}

// ScanInt scans and returns an integer from input
func (io *IO) ScanInt() int {
	return int(io.ScanInt64()) // Convert scanned int64 to int
}

// ScanInt2 scans and returns two integers from input
func (io *IO) ScanInt2() (int, int) {
	return int(io.ScanInt64()), int(io.ScanInt64()) // Return two integers
}

// ScanInt3 scans and returns three integers from input
func (io *IO) ScanInt3() (int, int, int) {
	return int(io.ScanInt64()), int(io.ScanInt64()), int(io.ScanInt64()) // Return three integers
}

// ScanInt4 scans and returns four integers from input
func (io *IO) ScanInt4() (int, int, int, int) {
	return int(io.ScanInt64()), int(io.ScanInt64()), int(io.ScanInt64()), int(io.ScanInt64()) // Return four integers
}

// ScanInts scans and returns a slice of integers from input
func (io *IO) ScanInts(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = io.ScanInt() // Scan each integer
	}
	return ints // Return the slice of integers
}

// Scan2DInts scans and returns a 2D slice of integers from input
func (io *IO) Scan2DInts(y, x int) [][]int {
	ints := make([][]int, y)
	for i := 0; i < y; i++ {
		ints[i] = io.ScanInts(x) // Scan each row of integers
	}
	return ints // Return the 2D slice of integers
}

// ScanInt64 scans and returns an int64 from input
func (io *IO) ScanInt64() int64 {
	i, err := strconv.ParseInt(io.ScanString(), 10, 64) // Parse scanned string to int64
	if err != nil {
		panic(err) // Panic if parsing fails
	}
	return i // Return the int64 value
}

// ScanFloat64 scans and returns a float64 from input
func (io *IO) ScanFloat64() float64 {
	i, _ := strconv.ParseFloat(io.ScanString(), 64) // Parse scanned string to float64
	return i // Return the float64 value
}

// ScanFloat64s scans and returns a slice of float64 from input
func (io *IO) ScanFloat64s(n int) []float64 {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		floats[i] = io.ScanFloat64() // Scan each float64
	}
	return floats // Return the slice of float64
}

// Println writes a line to the output
func (io *IO) Println(a ...interface{}) {
	fmt.Fprintln(io.writer, a...) // Print the provided arguments to the writer
}
