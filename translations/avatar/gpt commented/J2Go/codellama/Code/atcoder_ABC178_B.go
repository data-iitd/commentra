
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
	br   *bufio.Reader
	st   *strings.Reader
	temp string
}

// Constructor to initialize BufferedReader
func NewFastReader() *FastReader {
	return &FastReader{br: bufio.NewReader(os.Stdin), st: nil}
}

// Method to read the next token from input
func (f *FastReader) next() string {
	// Check if there are no tokens left to read
	if f.st == nil || !f.st.Scan() {
		f.temp, _ = f.br.ReadString('\n')
		f.st = strings.NewReader(f.temp)
		f.st.Scan()
	}
	return f.st.Text()
}

// Method to read the next integer from input
func (f *FastReader) nextInt() int {
	return int(f.nextInt64())
}

// Method to read the next long from input
func (f *FastReader) nextInt64() int64 {
	return int64(strconv.ParseInt(f.next(), 10, 64))
}

// Method to read the next double from input
func (f *FastReader) nextDouble() float64 {
	return float64(strconv.ParseFloat(f.next(), 64))
}

// Method to read the next line from input
func (f *FastReader) nextLine() string {
	return f.next()
}

// Method to compute (x^y) % mod using modular exponentiation
func modPower(x, y, mod int64) int64 {
	res := int64(1)
	x %= mod
	if x == 0 {
		return 0
	}

	// Loop until y becomes 0
	for y > 0 {
		// If y is odd, multiply x with result
		if y%2 == 1 {
			res = (res * x) % mod
		}
		y = y >> 1
		x = (x * x) % mod
	}
	return res
}

// Pair class to hold two related values
type pair struct {
	first  int64
	second int64
}

// Main method to execute the program
func main() {
	in := NewFastReader() // Create an instance of FastReader
	a := make([]int64, 4) // Array to hold four long integers

	// Read four long integers from input
	for i := 0; i < 4; i++ {
		a[i] = in.nextInt64()
	}

	// Calculate and print the maximum product of pairs from the array
	fmt.Println(int64(math.Max(a[0]*a[2], math.Max(a[1]*a[3], math.Max(a[0]*a[3], a[1]*a[2])))))
}

// 