
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader class to read input efficiently
type FastReader struct {
	br   *bufio.Reader
	st   *strings.Reader
	temp string
}

// NewFastReader function to create a new FastReader
func NewFastReader() *FastReader {
	return &FastReader{
		br: bufio.NewReader(os.Stdin),
	}
}

// Next function to read input efficiently
func (f *FastReader) Next() string {
	if f.st == nil || !f.st.Scan() {
		f.st = nil
		f.temp, _ = f.br.ReadString('\n')
		f.st = strings.NewReader(f.temp)
	}
	return f.st.Text()
}

// NextInt function to read input efficiently
func (f *FastReader) NextInt() int {
	return int(f.NextInt64())
}

// NextInt64 function to read input efficiently
func (f *FastReader) NextInt64() int64 {
	return int64(strconv.ParseInt(f.Next(), 10, 64))
}

// NextFloat function to read input efficiently
func (f *FastReader) NextFloat() float64 {
	return float64(strconv.ParseFloat(f.Next(), 64))
}

// NextLine function to read input efficiently
func (f *FastReader) NextLine() string {
	f.st = nil
	f.temp, _ = f.br.ReadString('\n')
	f.st = strings.NewReader(f.temp)
	return f.st.Text()
}

// ModPower function to calculate x^y mod mod using efficient exponentiation by squaring
func ModPower(x, y, mod int64) int64 {
	res := int64(1)
	x %= mod
	if x == 0 {
		return 0
	}
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % mod
		}
		y = y >> 1
		x = (x * x) % mod
	}
	return res
}

// Pair class to hold two elements of type T1 and T2
type Pair struct {
	First  int64
	Second int64
}

// Main function to read input, calculate the maximum product, and print the result
func main() {
	in := NewFastReader()
	a := make([]int64, 4)
	for i := 0; i < 4; i++ {
		a[i] = in.NextInt64()
	}
	fmt.Println(int64(math.Max(a[0]*a[2], math.Max(a[1]*a[3], math.Max(a[0]*a[3], a[1]*a[2])))))
}

// 