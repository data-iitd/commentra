
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Initialize a new scanner
func main() {
	sc := newScanner()

	// Read the first string from the standard input
	S := sc.next()

	// Check if the string starts with "YAKI"
	if strings.HasPrefix(S, "YAKI") {
		fmt.Println("Yes") // Print "Yes" if the condition is true
	} else {
		fmt.Println("No") // Print "No" if the condition is false
	}
}

// Minimum function
func min(a, b int) int {
	// Determine the minimum of two integers
	if a > b {
		return b
	}
	return a
}

// Maximum function
func max(a, b int) int {
	// Determine the maximum of two integers
	if a > b {
		return a
	}
	return b
}

// Scanner structure definition
type scanner struct {
	r   *bufio.Reader
	buf []byte
	p   int
}

// Initialize a new scanner instance
func newScanner() *scanner {
	rdr := bufio.NewReaderSize(os.Stdin, 1000)
	return &scanner{r: rdr}
}

// Next function to read the next token as a string
func (s *scanner) next() string {
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

// NextLine function to read the next line as a string
func (s *scanner) nextLine() string {
	s.pre()
	start := s.p
	s.p = len(s.buf)
	return string(s.buf[start:])
}

// NextInt function to read the next integer from the standard input
func (s *scanner) nextInt() int {
	v, _ := strconv.Atoi(s.next())
	return v
}

// NextIntArray function to read an array of integers from the standard input
func (s *scanner) nextIntArray() []int {
	s.pre()
	start := s.p
	result := []int{}
	for ; s.p < len(s.buf)+1; s.p++ {
		if s.p == len(s.buf) || s.buf[s.p] == ' ' {
			v, _ := strconv.ParseInt(string(s.buf[start:s.p]), 10, 0)
			result = append(result, int(v))
			start = s.p + 1
		}
	}
	return result
}

// Pre function to prepare the scanner for reading the next token
func (s *scanner) pre() {
	if s.p >= len(s.buf) {
		s.readLine()
		s.p = 0
	}
}

// ReadLine function to read a line from the standard input
func (s *scanner) readLine() {
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

