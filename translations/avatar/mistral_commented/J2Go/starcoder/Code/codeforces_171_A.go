package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining a static inner class FastReader for reading input
type FastReader struct {
	r *bufio.Reader
	s string
}

// Constructor for FastReader
func (f *FastReader) Init() {
	f.r = bufio.NewReader(os.Stdin)
	f.s = ""
}

// Method for reading next token
func (f *FastReader) ReadToken() string {
	f.s = ""
	for {
		if f.s == "" {
			f.s = f.next()
		}
		if f.s == "" {
			break
		}
		if f.s[0]!='' {
			break
		}
		f.s = f.s[1:]
	}
	if f.s == "" {
		return ""
	}
	i := 0
	for i < len(f.s) && f.s[i]!='' {
		i++
	}
	r := f.s[:i]
	f.s = f.s[i:]
	return r
}

// Methods for reading specific types of input
func (f *FastReader) ReadInt() int {
	r, _ := strconv.Atoi(f.ReadToken())
	return r
}

func (f *FastReader) ReadLong() int64 {
	r, _ := strconv.ParseInt(f.ReadToken(), 10, 64)
	return r
}

func (f *FastReader) ReadFloat() float64 {
	r, _ := strconv.ParseFloat(f.ReadToken(), 64)
	return r
}

func (f *FastReader) ReadString() string {
	return f.ReadToken()
}

func (f *FastReader) ReadLine() string {
	return f.s
}

// Main method
func main() {
	// Creating an instance of FastReader
	f := new(FastReader)
	f.Init()

	// Reading input for number of test cases
	n := f.ReadInt()

	// Reading input for number of operations
	m := f.ReadInt()

	// Calling reverse function for m and adding it to n
	t := reverse(m)
	fmt.Println(t + n)
}

// Function for reversing a number
func reverse(n int) int {
	// Base case for numbers less than 10
	if n < 10 {
		return n * 10
	}

	// Initializing variables
	t := n
	r := 0

	// Reversing the number
	for t > 0 {
		// Adding the digit to the reversed number
		r = (r * 10) + t%10

		// Moving to the next digit
		t = t / 10
	}

	// Returning the reversed number
	return r
}

