/*
URL:
https://atcoder.jp/contests/abc082/tasks/arc087_b
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

/********** FAU standard libraries **********/

// fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

// str := ReadString()
// i := ReadInt()
// X := ReadIntSlice(n)
// S := ReadRuneSlice()
// a := ReadFloat64()
// A := ReadFloat64Slice(n)

// str := ZeroPaddingRuneSlice(num, 32)
// str := PrintIntsLine(X...)

/*******************************************************************/

// Constants for general purpose use
const (
	MOD          = 1000000000 + 7 // Modulus value
	ALPHABET_NUM = 26              // Number of letters in the alphabet
	INF_INT64    = math.MaxInt64   // Maximum value for int64
	INF_BIT60    = 1 << 60         // 2^60
	INF_INT32    = math.MaxInt32   // Maximum value for int32
	INF_BIT30    = 1 << 30         // 2^30
	NIL          = -1              // Represents a null value

	// Constants for graph algorithms like Dijkstra and Prim
	WHITE = 0 // Unvisited state
	GRAY  = 1 // Visited state
	BLACK = 2 // Processed state
)

func init() {
	// Initialize custom input reading function and buffered output
	ReadString = newReadString(os.Stdin, bufio.ScanWords)
	stdout = bufio.NewWriter(os.Stdout)
}

var (
	S    []rune // Slice to hold the input string as runes
	x, y int   // Variables to hold the target coordinates

	dpx, dpy [8000][20000]bool // Dynamic programming tables for x and y coordinates
)

func main() {
	// Read the input string and target coordinates
	S = ReadRuneSlice()
	x, y = ReadInt2()

	F := []int{} // Slice to hold the lengths of consecutive 'F's
	cur := 0    // Current count of consecutive 'F's

	// Count consecutive 'F's and store in F
	for i := 0; i < len(S); i++ {
		if S[i] == 'F' {
			cur++
		} else {
			F = append(F, cur)
			cur = 0
		}
	}
	F = append(F, cur) // Append the last count of 'F's
	PrintfDebug("%v\n", F) // Debug output of the lengths of 'F's

	evens, odds := []int{}, []int{} // Slices to separate even and odd indexed counts
	// Separate counts into even and odd indexed slices
	for i := 0; i < len(F); i++ {
		if i%2 == 0 {
			evens = append(evens, F[i])
		} else {
			odds = append(odds, F[i])
		}
	}

	// Initialize the dynamic programming tables for x and y
	dpx[0][10000], dpy[0][10000] = true, true

	// Fill the dynamic programming table for even indexed counts
	for i := 0; i < len(evens); i++ {
		val := evens[i]
		for j := 2000; j <= 18000; j++ {
			if j+val <= 18000 {
				dpx[i+1][j+val] = dpx[i+1][j+val] || dpx[i][j]
			}
			if j-val >= 2000 && i != 0 {
				dpx[i+1][j-val] = dpx[i+1][j-val] || dpx[i][j]
			}
		}
	}

	// Fill the dynamic programming table for odd indexed counts
	for i := 0; i < len(odds); i++ {
		val := odds[i]
		for j := 2000; j <= 18000; j++ {
			if j+val <= 18000 {
				dpy[i+1][j+val] = dpy[i+1][j+val] || dpy[i][j]
			}
			if j-val >= 2000 {
				dpy[i+1][j-val] = dpy[i+1][j-val] || dpy[i][j]
			}
		}
	}

	// Check if the target coordinates can be reached
	if dpx[len(evens)][x+10000] && dpy[len(odds)][y+10000] {
		fmt.Println("Yes") // Output "Yes" if reachable
	} else {
		fmt.Println("No") // Output "No" if not reachable
	}
}

/*******************************************************************/

/*********** I/O ***********/

// Function declarations for input reading
var (
	// ReadString returns a WORD string.
	ReadString func() string
	stdout     *bufio.Writer
)

// newReadString initializes a new string reading function with a specified split function
func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+9)) // Set buffer size for large inputs
	r.Split(sf)

	return func() string {
		if !r.Scan() {
			panic("Scan failed") // Panic if scanning fails
		}
		return r.Text() // Return the scanned text
	}
}

// ReadInt returns an integer.
func ReadInt() int {
	return int(readInt64())
}

// ReadInt2 returns two integers.
func ReadInt2() (int, int) {
	return int(readInt64()), int(readInt64())
}

// ReadInt3 returns three integers.
func ReadInt3() (int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64())
}

// ReadInt4 returns four integers.
func ReadInt4() (int, int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64())
}

// ReadInt64 returns an integer as int64.
func ReadInt64() int64 {
	return readInt64()
}

// ReadInt64_2 returns two int64 values.
func ReadInt64_2() (int64, int64) {
	return readInt64(), readInt64()
}

// ReadInt64_3 returns three int64 values.
func ReadInt64_3() (int64, int64, int64) {
	return readInt64(), readInt64(), readInt64()
}

// ReadInt64_4 returns four int64 values.
func ReadInt64_4() (int64, int64, int64, int64) {
	return readInt64(), readInt64(), readInt64(), readInt64()
}

// readInt64 reads an int64 value from input
func readInt64() int64 {
	i, err := strconv.ParseInt(ReadString(), 0, 64)
	if err != nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i
}

// ReadIntSlice returns a slice of integers with n elements.
func ReadIntSlice(n int) []int {
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // Read each integer into the slice
	}
	return b
}

// ReadInt64Slice returns a slice of int64 with n elements.
func ReadInt64Slice(n int) []int64 {
	b := make([]int64, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt64() // Read each int64 into the slice
	}
	return b
}

// ReadFloat64 returns a float64 value.
func ReadFloat64() float64 {
	return float64(readFloat64())
}

// readFloat64 reads a float64 value from input
func readFloat64() float64 {
	f, err := strconv.ParseFloat(ReadString(), 64)
	if err != nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return f
}

// ReadFloatSlice returns a slice of float64 with n elements.
func ReadFloat64Slice(n int) []float64 {
	b := make([]float64, n)
	for i := 0; i < n; i++ {
		b[i] = ReadFloat64() // Read each float64 into the slice
	}
	return b
}

// ReadRuneSlice returns a slice of runes from input.
func ReadRuneSlice() []rune {
	return []rune(ReadString()) // Convert input string to rune slice
}

/*********** Debugging ***********/

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
func ZeroPaddingRuneSlice(n, digitsNum int) []rune {
	sn := fmt.Sprintf("%b", n) // Convert integer to binary string

	residualLength := digitsNum - len(sn) // Calculate needed padding
	if residualLength <= 0 {
		return []rune(sn) // Return without padding if no padding needed
	}

	// Create a slice of runes for the padding
	zeros := make([]rune, residualLength)
	for i := 0; i < len(zeros); i++ {
		zeros[i] = '0' // Fill with '0'
	}

	res := []rune{}
	res = append(res, zeros...) // Append zeros
	res = append(res, []rune(sn)...) // Append the binary string

	return res // Return the padded binary representation
}

// Strtoi is a wrapper of strconv.Atoi().
// If strconv.Atoi() returns an error, Strtoi calls panic.
func Strtoi(s string) int {
	if i, err := strconv.Atoi(s); err != nil {
		panic(errors.New("[argument error]: Strtoi only accepts integer string")) // Panic on error
	} else {
		return i // Return the converted integer
	}
}

// PrintIntsLine returns integers string delimited by a space.
func PrintIntsLine(A ...int) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i]) // Convert each integer to string
		res = append(res, []rune(str)...)

		if i != len(A)-1 {
			res = append(res, ' ') // Add space between integers
		}
	}

	return string(res) // Return the concatenated string
}

// PrintInts64Line returns integers string delimited by a space for int64.
func PrintInts64Line(A ...int64) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.FormatInt(A[i], 10) // Convert each int64 to string
		res = append(res, []rune(str)...)

		if i != len(A)-1 {
			res = append(res, ' ') // Add space between integers
		}
	}

	return string(res) // Return the concatenated string
}

// PrintfDebug is a wrapper of fmt.Fprintf(os.Stderr, format, a...)
func PrintfDebug(format string, a ...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...) // Print debug information to stderr
}

// PrintfBufStdout is a function for outputting strings to buffered os.Stdout.
// You may have to call stdout.Flush() finally.
func PrintfBufStdout(format string, a ...interface{}) {
	fmt.Fprintf(stdout, format, a...) // Print formatted output to buffered stdout
}
