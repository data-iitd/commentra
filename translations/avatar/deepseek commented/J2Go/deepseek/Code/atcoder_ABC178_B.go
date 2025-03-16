package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader struct to read input efficiently
type FastReader struct {
	sc *bufio.Scanner
}

// NewFastReader creates a new FastReader
func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

// ReadString reads the next token from the input
func (r *FastReader) ReadString() string {
	r.sc.Scan()
	return r.sc.Text()
}

// ReadInt reads the next integer from the input
func (r *FastReader) ReadInt() int {
	num, _ := strconv.Atoi(r.ReadString())
	return num
}

// ReadLong reads the next long from the input
func (r *FastReader) ReadLong() int64 {
	num, _ := strconv.ParseInt(r.ReadString(), 10, 64)
	return num
}

// ReadDouble reads the next double from the input
func (r *FastReader) ReadDouble() float64 {
	num, _ := strconv.ParseFloat(r.ReadString(), 64)
	return num
}

// Function to calculate x^y mod mod using efficient exponentiation by squaring
func modPower(x, y, mod int) int {
	res := 1
	x %= mod
	if x == 0 {
		return 0
	}
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % mod
		}
		y >>= 1
		x = (x * x) % mod
	}
	return res
}

// Generic pair struct to hold two elements of type T1 and T2
type pair struct {
	first  int
	second int
}

// Main function to read input, calculate the maximum product, and print the result
func main() {
	in := NewFastReader()
	var a [4]int64
	for i := 0; i < 4; i++ {
		a[i] = in.ReadLong()
	}
	fmt.Println(max(a[0]*a[2], max(a[1]*a[3], max(a[0]*a[3], a[1]*a[2]))))
}

// Helper function to find the maximum of two integers
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

