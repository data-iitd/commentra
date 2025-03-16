// Package main is the entry point of the program
package main

import (
	// Importing necessary packages
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a new scanner instance
	sc := NewScanner()

	// Reading the first integer from the standard input
	n := sc.NextInt()
	// Initializing the answer variable
	ans := 0.0

	// Iterating through the given number of integers
	for i := 0; i < n; i++ {
		// Reading the next integer from the standard input
		tmp := 1 / float64(sc.NextInt())
		// Adding the reciprocal of the current integer to the answer
		ans += tmp
	}

	// Printing the final answer
	fmt.Printf("%v\n", 1/ans)

}

// Scanner type definition
type Scanner struct {
	// Defining the reader instance
	r   *bufio.Reader
	buf []byte
	p   int
}

// NewScanner function initializes a new scanner instance
func NewScanner() *Scanner {
	// Creating a new buffered reader instance
	rdr := bufio.NewReaderSize(os.Stdin, 1000)
	// Initializing the scanner instance with the reader instance
	return &Scanner{r: rdr}
}

// Next function reads the next token from the standard input
func (s *Scanner) Next() string {
	// Preprocessing the input buffer
	s.pre()
	// Reading the next token from the input buffer
	start := s.p
	for ; s.p < len(s.buf); s.p++ {
		// Checking if the current character is a whitespace character
		if s.buf[s.p] == ' ' {
			// If yes, then setting the end position of the token
			break
		}
	}
	// Reading the token from the input buffer
	result := string(s.buf[start:s.p])
	// Incrementing the position of the input buffer pointer
	s.p++
	// Returning the token
	return result
}

// NextLine function reads the next line from the standard input
func (s *Scanner) NextLine() string {
	// Preprocessing the input buffer
	s.pre()
	// Reading the next line from the input buffer
	start := s.p
	s.p = len(s.buf)
	// Reading the rest of the line if available
	s.readLine()
	// Creating a slice from the current position to the end of the input buffer
	result := string(s.buf[start:])
	// Returning the line
	return result
}

// NextInt function reads the next integer from the standard input
func (s *Scanner) NextInt() int {
	// Reading the next token as a string
	token := s.Next()
	// Converting the token to an integer
	v, _ := strconv.Atoi(token)
	// Returning the integer
	return v
}

// NextIntArray function reads an array of integers from the standard input
func (s *Scanner) NextIntArray() []int {
	// Reading the next token as a string
	token := s.Next()
	// Initializing an empty slice
	result := []int{}
	// Reading each integer from the standard input and appending it to the slice
	for {
		// Checking if the current token is an integer
		if len(token) > 0 && token[len(token)-1] >= '0' && token[len(token)-1] <= '9' {
			// If yes, then converting the token to an integer and appending it to the slice
			v, _ := strconv.Atoi(token)
			result = append(result, v)
			// Reading the next token
			token = s.Next()
			// If the current token is not a space character, then there is an error in the input
			if token[0] != ' ' {
				panic("Invalid input")
			}
		} else {
			// If the current token is not an integer, then the input is invalid
			panic("Invalid input")
		}
	}
	// Returning the slice
	return result
}

// NextMap function reads a map from the standard input
func (s *Scanner) NextMap() map[int]bool {
	// Reading the next token as a string
	token := s.Next()
	// Initializing an empty map
	mp := map[int]bool{}
	// Reading each key-value pair from the standard input and adding it to the map
	for {
		// Checking if the current token is an integer
		if len(token) > 0 && token[len(token)-1] >= '0' && token[len(token)-1] <= '9' {
			// If yes, then converting the token to an integer and adding it as a key to the map
			k, _ := strconv.Atoi(token)
			mp[k] = true
			// Reading the next token
			token = s.Next()
			// If the current token is not a colon character, then there is an error in the input
			if token[0] != ':' {
				panic("Invalid input")
			}
			// Reading the next token as a boolean value
			v := s.Next() == "true"
			// Adding the value to the map
			mp[k] = v
			// If the current token is not a space character, then there is an error in the input
			if token[0] != ' ' {
				panic("Invalid input")
			}
		} else {
			// If the current token is not an integer, then the input is invalid
			panic("Invalid input")
		}
		// Checking if the next token is the end of the input
		if token == "" {
			break
		}
	}
	// Returning the map
	return mp
}

// pre function preprocesses the input buffer
func (s *Scanner) pre() {
	// If the position of the input buffer pointer is at the end of the buffer, then reading the next line from the standard input
	if s.p >= len(s.buf) {
		s.readLine()
		s.p = 0
	}
}

// readLine function reads a line from the standard input and stores it in the input buffer
func (s *Scanner) readLine() {
	// Reading a line from the standard input
	l, p, e := s.r.ReadLine()
	// If there is an error, then panicking
	if e != nil {
		panic(e)
	}
	// Appending the line to the input buffer
	s.buf = append(s.buf, l...)
	// Setting the position of the input buffer pointer to the end of the line
	s.p = len(s.buf)
}