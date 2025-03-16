
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// A private nested class SimpleScanner for reading input
type SimpleScanner struct {
	in  *bufio.Reader
	eof bool
}

// Constructor for initializing the SimpleScanner object
func NewSimpleScanner(in *bufio.Reader) *SimpleScanner {
	return &SimpleScanner{in: in}
}

// A method for reading a single character from the input stream
func (scanner *SimpleScanner) read() rune {
	// If the character buffer is empty, refill it
	if scanner.eof {
		return -1
	}
	b, _, err := scanner.in.ReadRune()
	if err!= nil {
		scanner.eof = true
		return -1
	}
	return b
}

// A method for checking the end-of-file condition
func (scanner *SimpleScanner) checkEof() {
	if scanner.eof {
		panic("No more input")
	}
}

// A method for reading a single character
func (scanner *SimpleScanner) nextChar() rune {
	scanner.checkEof()
	b := scanner.read()
	scanner.checkEof()
	return b
}

// A method for reading a string
func (scanner *SimpleScanner) next() string {
	var sb strings.Builder
	for {
		b := scanner.read()
		if b == -1 {
			break
		}
		sb.WriteRune(b)
	}
	return sb.String()
}

// A method for reading an integer
func (scanner *SimpleScanner) nextInt() int {
	i, err := strconv.Atoi(scanner.next())
	if err!= nil {
		panic(err)
	}
	return i
}

// A method for reading a long integer
func (scanner *SimpleScanner) nextLong() int64 {
	i, err := strconv.ParseInt(scanner.next(), 10, 64)
	if err!= nil {
		panic(err)
	}
	return i
}

// A method for reading a double
func (scanner *SimpleScanner) nextDouble() float64 {
	i, err := strconv.ParseFloat(scanner.next(), 64)
	if err!= nil {
		panic(err)
	}
	return i
}

func main() {
	// Creating a SimpleScanner object for reading input and a PrintWriter object for writing output
	scanner := NewSimpleScanner(bufio.NewReader(os.Stdin))
	writer := bufio.NewWriter(os.Stdout)

	// Reading input variables from the user
	r := scanner.nextInt() // Reading the first integer 'r' from the user
	d := scanner.nextInt() // Reading the second integer 'd' from the user
	x := scanner.nextLong() // Reading the long integer 'x' from the user

	// Running the loop for 10 iterations
	for i := 0; i < 10; i++ {
		// Multiplying 'r' with 'x' and subtracting 'd' from it
		x = r*x - d

		// Writing the result to the output stream
		fmt.Fprintln(writer, x)
	}

	// Closing the output stream
	writer.Flush()
}

// 