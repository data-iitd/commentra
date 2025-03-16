package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader class to handle fast input
type FastReader struct {
	br *bufio.Reader
	st *strings.Reader
}

// Constructor initializes BufferedReader for input
func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin), st: nil}
}

// Method to read the next token from input
func (f *FastReader) next() string {
	// Check if there are no more tokens available
	if f.st == nil || !f.st.Scan() {
		var str string
		str, _ = f.br.ReadString('\n')
		f.st = strings.NewReader(str)
	}
	// Return the next token
	return f.st.Text()
}

// Method to read the next integer from input
func (f *FastReader) nextInt() int {
	return int(f.nextInt64())
}

// Method to read the next long from input
func (f *FastReader) nextInt64() int64 {
	return int64(f.nextInt32())
}

// Method to read the next int32 from input
func (f *FastReader) nextInt32() int32 {
	return int32(f.nextInt16())
}

// Method to read the next int16 from input
func (f *FastReader) nextInt16() int16 {
	return int16(f.nextInt8())
}

// Method to read the next int8 from input
func (f *FastReader) nextInt8() int8 {
	return int8(f.nextInt64())
}

// Method to read the next double from input
func (f *FastReader) nextDouble() float64 {
	return float64(f.nextFloat64())
}

// Method to read the next float64 from input
func (f *FastReader) nextFloat64() float64 {
	return float64(f.nextFloat32())
}

// Method to read the next float32 from input
func (f *FastReader) nextFloat32() float32 {
	return float32(f.nextFloat16())
}

// Method to read the next float16 from input
func (f *FastReader) nextFloat16() float32 {
	return float32(f.nextFloat8())
}

// Method to read the next float8 from input
func (f *FastReader) nextFloat8() float32 {
	return float32(f.nextFloat64())
}

// Method to read the next line from input
func (f *FastReader) nextLine() string {
	var str string
	str, _ = f.br.ReadString('\n')
	return str
}

// Method to reverse the digits of an integer n
func reverse(n int) int {
	// If n is a single digit, return n multiplied by 10
	if n < 10 {
		return n * 10
	}

	t := n
	r := 0

	// Loop to reverse the digits of n
	for t > 0 {
		r = (r * 10) + t%10 // Add the last digit of t to r
		t = t / 10          // Remove the last digit from t
	}

	// Return the reversed integer
	return r
}

func main() {
	// Create an instance of FastReader for input
	sc := NewFastReader()

	// Read two integers n and m from input
	n := sc.nextInt()
	m := sc.nextInt()

	// Reverse the integer m and store the result in t
	t := reverse(m)

	// Print the sum of t and n
	fmt.Println(t + n)
}

// 