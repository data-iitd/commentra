// Package main contains the main function for solving the problem.
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"
	"strconv"
)

// Constants for large prime numbers used in modular arithmetic.
const (
	// big prime
	INF  = 1000000007
	INF2 = 1000000009
	INF3 = 998244353
)

// Global variable for debug mode.
var DEBUG = false

// -----------------------------------------------------------------------------
// IO helper functions

// Returns next token from input. It must be initialized by SetInput() before the first call.
var nextToken func() ([]byte, error)
var nextLine func() ([]byte, error)

// Holds a buffer for output. It must be initialized by SetOutput().
// All IO functions (read*() and [e]print*()) should write to OutputWriter instead of this.
var OutputBuffer *bufio.Writer

// Holds an io.Writer. It must be initialized by SetOutput()
var OutputWriter io.Writer

// Set IO functions for interactive input/output.
func SetInteractive(w io.Writer, r io.Reader) {
	SetUnbufferedInput(r)
	OutputBuffer = nil
	OutputWriter = w
}

// Setup OutputBuffer and OutputWriter.
func SetOutput(w io.Writer) {
	OutputBuffer = bufio.NewWriter(w)
	OutputWriter = OutputBuffer
}

// Flushes OutputBuffer
func Flush() {
	if OutputBuffer != nil {
		OutputBuffer.Flush()
	}
}

// Returns true if c is a white space
func IsSpace(c byte) bool {
	switch c {
	case '\t', '\n', '\v', '\f', '\r', ' ':
		return true
	}
	return false
}

func IsNewLine(c byte) bool {
	switch c {
	case '\n', '\r':
		return true
	}
	return false
}

// Setup nextToken with input buffer.
func SetInput(r io.Reader) {
	buf := new(bytes.Buffer)
	var b []byte

	var i int
	rest := func() ([]byte, error) {
		for i < len(b) && IsSpace(b[i]) {
			i++
		}
		if i == len(b) {
			return nil, io.ErrUnexpectedEOF
		}
		j := i
		for i < len(b) && !IsSpace(b[i]) {
			i++
		}
		return b[j:i], nil
	}
	initial := func() ([]byte, error) {
		io.Copy(buf, r)
		b = buf.Bytes()
		nextToken = rest
		return rest()
	}
	nextToken = initial

	restLn := func() ([]byte, error) {
		for i < len(b) && IsNewLine(b[i]) {
			i++
		}
		if i == len(b) {
			return nil, io.ErrUnexpectedEOF
		}
		j := i
		for i < len(b) && !IsNewLine(b[i]) {
			i++
		}
		return b[j:i], nil
	}

	initialLn := func() ([]byte, error) {
		io.Copy(buf, r)
		b = buf.Bytes()
		nextLine = restLn
		return restLn()
	}
	nextLine = initialLn
}

// Setup nextToken without input buffer.
func SetUnbufferedInput(r io.Reader) {
	buf := bufio.NewReader(r)
	var b []byte

	var i int
	nextToken = func() ([]byte, error) {
		var err error
		if i == len(b) {
			b, err = buf.ReadBytes('\n')
			if err != nil {
				return nil, err
			}
			i = 0
			j := len(b) - 1
			for 0 <= j && IsSpace(b[j]) {
				j--
			}
			b = b[0 : j+1]
		}
		for i < len(b) && IsSpace(b[i]) {
			i++
		}
		j := i
		for i < len(b) && !IsSpace(b[i]) {
			i++
		}
		if i == j {
			return nil, io.ErrUnexpectedEOF
		}
		return b[j:i], nil
	}
}

// -----------------------------------------------------------------------------
// IO functions

// Reads next token and return it as []byte
func readb() []byte {
	b, err := nextToken()
	if err != nil {
		panic(err)
	}
	return b[:len(b):len(b)]
}

// Reads next token and return it as string
func reads() string {
	return string(readb())
}

// Read next line as []byte. Trailing '\n' will not be included.
// See also comments on readb()
func readbln() []byte {
	b, err := nextLine()
	if err != nil {
		panic(err)
	}
	return b[:len(b):len(b)]
}

// Read next line as string
func readsln() string {
	return string(readbln())
}

// Reads next token and return it as int64
func readll() int64 {
	i, err := strconv.ParseInt(reads(), 10, 64)
	if err != nil {
		panic(err.Error())
	}
	return i
}

// Reads next token and return it as int
func readi() int {
	return int(readll())
}

// Reads next token and return it as float64
func readf() float64 {
	f, err := strconv.ParseFloat(reads(), 64)
	if err != nil {
		panic(err.Error())
	}
	return f
}

// Write args to OutputWriter with the format f
func printf(f string, args ...interface{}) (int, error) {
	return fmt.Fprintf(OutputWriter, f, args...)
}

// Write args to OutputWriter without format
func println(args ...interface{}) (int, error) {
	return fmt.Fprintln(OutputWriter, args...)
}

// Write args to stderr with the format f
func eprintf(f string, args ...interface{}) (int, error) {
	return fmt.Fprintf(os.Stderr, f, args...)
}

// Write args to stderr without format
func eprintln(args ...interface{}) (int, error) {
	return fmt.Fprintln(os.Stderr, args...)
}

func debugf(f string, args ...interface{}) {
	if !DEBUG {
		return
	}
	fmt.Fprintf(os.Stderr, f, args...)
}

func debug(args ...interface{}) {
	if !DEBUG {
		return
	}
	fmt.Fprintln(os.Stderr, args...)
}

// -----------------------------------------------------------------------------
// Utilities

func sumSlice(a []int) int {
	var res int
	for _, v := range a {
		res += v
	}
	return res
}

func sumSlicell(a []int64) int64 {
	var res int64
	for _, v := range a {
		res += v
	}
	return res
}

// -----------------------------------------------------------------------------
// Simple math functions

// min returns the minimum of two integers.
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// minll returns the minimum of two int64.
func minll(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// minf returns the minimum of two float64.
func minf(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

// max returns the maximum of two integers.
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

// maxll returns the maximum of two int64.
func maxll(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

// maxf returns the maximum of two float64.
func maxf(a, b float64) float64 {
	if a < b {
		return b
	}
	return a
}

// abs returns the absolute value of an integer.
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// absll returns the absolute value of an int64.
func absll(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

// absf returns the absolute value of a float64.
func absf(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}

// egcd returns the greatest common divisor of a and b, along with x and y such that a*x + b*y = gcd.
func egcd(a, b int) (int, int, int) {
	if b == 0 {
		return a, 1, 0
	}
	d, x, y := egcd(b, a%b)
	return d, y, x - a/b*y
}

func egcdll(a, b int64) (int64, int64, int64) {
	if b == 0 {
		return a, 1, 0
	}
	d, x, y := egcdll(b, a%b)
	return d, y, x - a/b*y
}

// gcd returns the greatest common divisor of two integers.
func gcd(a, b int) int {
	d, _, _ := egcd(a, b)
	return d
}

// gcdll returns the greatest common divisor of two int64.
func gcdll(a, b int64) int64 {
	d, _, _ := egcdll(a, b)
	return d
}

// -----------------------------------------------------------------------------
// Main function

func init() {
	// for non-interactive
	SetInput(os.Stdin)
	SetOutput(os.Stdout)

	// Enable below when interactive. Its ok to leave above intact.
	SetInteractive(os.Stdout, os.Stdin)
}

// Main function for solving the problem.
func main() {
	defer Flush()

	// Read input
	h, w, a := readi(), readi(), readi()
	m := make([][]int, h)
	for i := 0; i < h; i++ {
		m[i] = make([]int, w)
		s := reads()
		for j := 0; j < w; j++ {
			m[i][j] = int(s[j])
		}
	}

	// Solve the problem
	answer := solve(h, w, a, m)

	// Print the result
	println(answer)
}

// Function to count the number of black cells in a grid.
func countBlack(h, w int, m [][]int) int {
	count := 0
	debug("new table")
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if m[i][j] == Black {
				count++
			}
		}
		debug(m[i])
	}
	debug("result : ", count)
	return count
}

// Function to solve the problem.
func solve(h, w, a int, m [][]int) int {
	result := 0
	for i := 0; i < 1<<h; i++ {
		for k := 0; k < 1<<w; k++ {
			tmp := make([][]int, h)
			for j := 0; j < h; j++ {
				tmp[j] = make([]int, w)
				copy(tmp[j], m[j])
			}
			for j := 0; j < h; j++ {
				hPainted := (1 << j & i)
				if hPainted > 0 {
					debug("painted ", j, 1<<j, i, hPainted)
					for l := 0; l < w; l++ {
						tmp[j][l] = 1
					}
				}
			}
			for j := 0; j < w; j++ {
				wPainted := (1 << j & k)
				if wPainted > 0 {
					for l := 0; l < h; l++ {
						tmp[l][j] = 1
					}
				}
			}
			debug("i", strconv.FormatInt(int64(i), 2))
			debug("k", strconv.FormatInt(int64(k), 2))
			if countBlack(h, w, tmp) == a {
				result++
			}
		}
	}
	return result
}

// Constants for black cell representation.
const Black int = 35
