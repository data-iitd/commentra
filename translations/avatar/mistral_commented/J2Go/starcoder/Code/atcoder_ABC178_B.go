
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining a FastReader class for reading input
type FastReader struct {
	r *bufio.Reader
	s string
}

// Constructor for initializing the FastReader object
func (f *FastReader) Init() {
	f.r = bufio.NewReader(os.Stdin)
	f.s = ""
}

// Method for reading the next token from the input
func (f *FastReader) next() string {
	if f.s == "" {
		f.s = f.readLine()
	}
	tok := f.s
	f.s = ""
	return tok
}

// Method for reading the next line from the input
func (f *FastReader) readLine() string {
	r, err := f.r.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	return strings.TrimRight(r, "\r\n")
}

// Method for reading the next integer from the input
func (f *FastReader) nextInt() int {
	i, err := strconv.Atoi(f.next())
	if err!= nil {
		panic(err)
	}
	return i
}

// Method for reading the next long integer from the input
func (f *FastReader) nextLong() int64 {
	i, err := strconv.ParseInt(f.next(), 10, 64)
	if err!= nil {
		panic(err)
	}
	return i
}

// Method for reading the next double from the input
func (f *FastReader) nextDouble() float64 {
	i, err := strconv.ParseFloat(f.next(), 64)
	if err!= nil {
		panic(err)
	}
	return i
}

// Defining a generic pair class for storing two elements of different types
type pair struct {
	first  interface{}
	second interface{}
}

// Method for calculating x raised to the power of y modulo mod
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

// Main method for executing the program
func main() {
	f := FastReader{}
	f.Init()
	a := make([]int64, 4)
	for i := 0; i < 4; i++ {
		a[i] = f.nextLong()
	}
	result := int64(0)
	result = int64(math.Max(float64(a[0]*a[2]), math.Max(float64(a[1]*a[3]), math.Max(float64(a[0]*a[3]), float64(a[1]*a[2])))))
	fmt.Println(result)
}

