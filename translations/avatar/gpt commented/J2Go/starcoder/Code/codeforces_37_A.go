package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastScanner is a helper class for reading input
type FastScanner struct {
	s   *bufio.Scanner
	buf []byte
}

// NewFastScanner returns a new instance of FastScanner
func NewFastScanner() *FastScanner {
	return &FastScanner{
		s:   bufio.NewScanner(os.Stdin),
		buf: make([]byte, 0),
	}
}

// Split splits the input by a space, returning a slice of strings
func (f *FastScanner) Split() []string {
	f.buf = append(f.buf,'')
	f.s.Scan()
	f.buf = append(f.buf, f.s.Bytes()...)
	return strings.Split(string(f.buf), " ")
}

// NextInt32 reads the next integer from the input
func (f *FastScanner) NextInt32() int32 {
	i, _ := strconv.ParseInt(f.s.Text(), 10, 32)
	return int32(i)
}

// NextInt64 reads the next integer from the input
func (f *FastScanner) NextInt64() int64 {
	i, _ := strconv.ParseInt(f.s.Text(), 10, 64)
	return i
}

// NextString reads the next string from the input
func (f *FastScanner) NextString() string {
	f.s.Scan()
	return f.s.Text()
}

// NextFloat64 reads the next float from the input
func (f *FastScanner) NextFloat64() float64 {
	i, _ := strconv.ParseFloat(f.s.Text(), 64)
	return i
}

func main() {
	// Create a new instance of FastScanner to read input
	scanner := NewFastScanner()

	// Read the number of integers to be processed
	n := scanner.NextInt32()

	// Initialize a HashMap to store the frequency of each integer
	freq := make(map[int32]int32)

	// Loop through the input integers and populate the frequency map
	for i := int32(0); i < n; i++ {
		val := scanner.NextInt32()
		// Update the count of the integer in the map
		freq[val]++
	}

	// Initialize a variable to track the maximum frequency found
	max := int32(0)

	// Iterate through the entries in the frequency map to find the maximum frequency
	for _, v := range freq {
		// Update max if the current frequency is greater than the current max
		if v > max {
			max = v
		}
	}

	// Print the maximum frequency and the number of unique integers
	fmt.Println(max, len(freq))
}

// 