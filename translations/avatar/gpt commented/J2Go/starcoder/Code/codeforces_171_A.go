package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader is a wrapper around bufio.Reader.
// It provides fast input reading in the form of
// a space-delimited string of words.
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a new instance of FastReader.
func NewFastReader(r *bufio.Reader) *FastReader {
	return &FastReader{r: r}
}

// ReadWord returns the next word from the input,
// or an empty string if an error occurs.
func (f *FastReader) ReadWord() string {
	var (
		isWord bool
		err    error
		c      byte
		s      []byte
	)
	for isWord = true; isWord; {
		c, err = f.r.ReadByte()
		if err!= nil {
			return ""
		}
		if c =='' || c == '\n' || c == '\r' || c == '\t' {
			isWord = false
			continue
		}
		s = append(s, c)
	}
	return string(s)
}

// ReadInt returns the next integer from the input,
// or 0 if an error occurs.
func (f *FastReader) ReadInt() int {
	var (
		s   string
		err error
		i   int
	)
	s, err = f.ReadWord()
	if err!= nil {
		return 0
	}
	i, err = strconv.Atoi(s)
	if err!= nil {
		return 0
	}
	return i
}

// ReadInt64 returns the next int64 from the input,
// or 0 if an error occurs.
func (f *FastReader) ReadInt64() int64 {
	var (
		s   string
		err error
		i   int64
	)
	s, err = f.ReadWord()
	if err!= nil {
		return 0
	}
	i, err = strconv.ParseInt(s, 10, 64)
	if err!= nil {
		return 0
	}
	return i
}

// ReadFloat64 returns the next float64 from the input,
// or 0 if an error occurs.
func (f *FastReader) ReadFloat64() float64 {
	var (
		s   string
		err error
		i   float64
	)
	s, err = f.ReadWord()
	if err!= nil {
		return 0
	}
	i, err = strconv.ParseFloat(s, 64)
	if err!= nil {
		return 0
	}
	return i
}

// ReadString returns the next string from the input,
// or an empty string if an error occurs.
func (f *FastReader) ReadString() string {
	var (
		s   string
		err error
	)
	s, err = f.ReadWord()
	if err!= nil {
		return ""
	}
	return s
}

// ReadLine returns the next line from the input,
// or an empty string if an error occurs.
func (f *FastReader) ReadLine() string {
	var (
		s   string
		err error
	)
	s, err = f.r.ReadString('\n')
	if err!= nil {
		return ""
	}
	return s
}

func main() {
	// Read input from stdin
	f := NewFastReader(bufio.NewReader(os.Stdin))

	// Read two integers n and m from input
	n := f.ReadInt()
	m := f.ReadInt()

	// Reverse the integer m and store the result in t
	t := reverse(m)

	// Print the sum of t and n
	fmt.Println(t + n)
}

// reverse reverses the digits of an integer n
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
		t = t / 10           // Remove the last digit from t
	}

	// Return the reversed integer
	return r
}

