package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

func main() {
	// Initialize FastScanner for efficient input reading
	in := bufio.NewScanner(os.Stdin)
	// Create a Scanner object for standard input
	sc := bufio.NewScanner(os.Stdin)
	// Create a PrintWriter object for output
	o := bufio.NewWriter(os.Stdout)

	// Read the number of pairs (n) and the minimum score (s)
	n, _ := strconv.Atoi(sc.Text())
	s, _ := strconv.Atoi(sc.Text())

	// Initialize a variable to keep track of the maximum sum of pairs
	max := 0

	// Loop through each pair of integers
	for n > 0 {
		// Read the two integers f and t
		f, _ := strconv.Atoi(sc.Text())
		t, _ := strconv.Atoi(sc.Text())
		// Update max if the sum of f and t is greater than the current max
		if max < f+t {
			max = f + t
		}
		n--
	}

	// Print the maximum value between max and s
	fmt.Fprintln(o, max)
	// Close the PrintWriter
	o.Flush()
}

// FastScanner class for efficient input handling
type FastScanner struct {
	s   *bufio.Scanner
	buf *bytes.Buffer
}

func NewFastScanner() *FastScanner {
	return &FastScanner{
		s:   bufio.NewScanner(os.Stdin),
		buf: bytes.NewBuffer([]byte{}),
	}
}

func (f *FastScanner) Init() {
	f.s.Buffer(f.buf.Bytes(), f.buf.Cap())
	f.s.Split(bufio.ScanWords)
}

func (f *FastScanner) Next() string {
	f.s.Scan()
	return f.s.Text()
}

func (f *FastScanner) NextLine() string {
	s, _ := f.s.Scan()
	return s
}

func (f *FastScanner) NextInt() int {
	i, _ := strconv.Atoi(f.Next())
	return i
}

func (f *FastScanner) NextInt64() int64 {
	i, _ := strconv.ParseInt(f.Next(), 10, 64)
	return i
}

func (f *FastScanner) NextFloat() float64 {
	i, _ := strconv.ParseFloat(f.Next(), 64)
	return i
}

func (f *FastScanner) NextBool() bool {
	i, _ := strconv.ParseBool(f.Next())
	return i
}

func (f *FastScanner) NextRune() rune {
	s := f.Next()
	if len(s) == 0 {
		return -1
	}
	return []rune(s)[0]
}

func (f *FastScanner) NextByte() byte {
	s := f.Next()
	if len(s) == 0 {
		return -1
	}
	return s[0]
}

func (f *FastScanner) NextBytes() []byte {
	s := f.Next()
	if len(s) == 0 {
		return []byte{}
	}
	return []byte(s)
}

func (f *FastScanner) NextString() string {
	return f.Next()
}

func (f *FastScanner) NextStrings(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = f.Next()
	}
	return a
}

func (f *FastScanner) NextInts(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = f.NextInt()
	}
	return a
}

func (f *FastScanner) NextInts64(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = f.NextInt64()
	}
	return a
}

func (f *FastScanner) NextFloats(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = f.NextFloat()
	}
	return a
}

func (f *FastScanner) NextBools(n int) []bool {
	a := make([]bool, n)
	for i := 0; i < n; i++ {
		a[i] = f.NextBool()
	}
	return a
}

func (f *FastScanner) NextRunes(n int) []rune {
	a := make([]rune, n)
	for i := 0; i < n; i++ {
		a[i] = f.NextRune()
	}
	return a
}

func (f *FastScanner) NextBytes(n int) []byte {
	a := make([]byte, n)
	for i := 0; i < n; i++ {
		a[i] = f.NextByte()
	}
	return a
}

func (f *FastScanner) NextStrings(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = f.NextString()
	}
	return a
}

// 