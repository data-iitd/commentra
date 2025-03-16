package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	//	"strings"
	"sort"
)

// Initialize a new scanner object
func main() {
	sc := NewScanner()

	// Read the number of elements in the array from the standard input
	n := sc.NextInt()

	// Allocate memory for the array of size n
	arr := make([]float64, n)

	// Read n integers from the standard input and store them in the array
	for i := 0; i < n; i++ {
		arr[i] = float64(sc.NextInt())
	}

	// Sort the array in ascending order
	sort.Float64s(arr)

	// Initialize a variable prev to store the previous element in the sorted array
	prev := arr[0]

	// Iterate through the sorted array from the second element to the last
	for i := 1; i < len(arr); i++ {
		// Calculate the average of the previous and current elements
		prev = (prev + arr[i]) / 2
	}

	// Print the result to the standard output
	fmt.Printf("%v\n", prev)
}

// Initialize a new scanner object
type Scanner struct {
	r   *bufio.Reader
	buf []byte
	p   int
}

// Create a new scanner object
func NewScanner() *Scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000)
	return &Scanner{r: rdr}
}

// Read a single token from the standard input
func (s *Scanner) Next() string {
	s.pre()
	start := s.p
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break
		}
	}
	result := string(s.buf[start:s.p])
	s.p++
	return result
}

// Read a line from the standard input
func (s *Scanner) NextLine() string {
	s.pre()
	start := s.p
	s.p = len(s.buf)
	return string(s.buf[start:])
}

// Read an integer from the standard input
func (s *Scanner) NextInt() int {
	v, _ := strconv.Atoi(s.Next())
	return v
}

// Read an array of integers from the standard input
func (s *Scanner) NextIntArray() []int {
	s.pre()
	start := s.p
	result := []int{}
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			v, _ := strconv.Atoi(string(s.buf[start:s.p]))
			result = append(result, v)
			start = s.p + 1
		}
	}
	v, _ := strconv.Atoi(string(s.buf[start:s.p]))
	result = append(result, v)

	return result
}

// Read a map from the standard input
func (s *Scanner) NextMap() map[int]bool {
	s.pre()
	start := s.p
	mp := map[int]bool{}
	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			v, _ := strconv.Atoi(string(s.buf[start:s.p]))
			mp[v] = true
			start = s.p + 1
		}
	}
	v, _ := strconv.Atoi(string(s.buf[start:s.p]))
	mp[v] = true

	return mp
}

// Prepare the scanner for the next read operation
func (s *Scanner) pre() {
	if s.p >= len(s.buf) {
		s.readLine()
		s.p = 0
	}
}

// Read a line from the standard input
func (s *Scanner) readLine() {
	s.buf = make([]byte, 0)
	for {
		l, p, e := s.r.ReadLine()
		if e != nil {
			panic(e)
		}
		s.buf = append(s.buf, l...)
		if !p {
			break
		}
	}
}
