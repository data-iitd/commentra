package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a SimpleScanner instance to read from standard input
	scanner := NewSimpleScanner(os.Stdin)
	// Create a PrintWriter instance to write to standard output
	writer := bufio.NewWriter(os.Stdout)

	// Read three integers from the input
	r := scanner.nextInt()
	d := scanner.nextInt()
	x := scanner.nextLong()

	// Perform the calculation in a loop and print the result 10 times
	for i := 0; i < 10; i++ {
		x = int64(r)*x - int64(d)
		writer.WriteString(fmt.Sprintf("%d\n", x))
	}

	// Close the PrintWriter to ensure all data is flushed to the output
	writer.Flush()
}

// Define the SimpleScanner struct to simplify input reading
type SimpleScanner struct {
	in   *bufio.Reader
	buf  []byte
	eof  bool
}

// Constructor to initialize the SimpleScanner with an InputStream
func NewSimpleScanner(in io.Reader) *SimpleScanner {
	return &SimpleScanner{in: bufio.NewReader(in)}
}

// Method to read a character from the buffer or input stream
func (s *SimpleScanner) read() byte {
	if len(s.buf) == 0 {
		if s.eof {
			return 0
		}
		var err error
		s.buf, err = s.in.ReadBytes('\n')
		if err != nil {
			s.eof = true
			return 0
		}
	}
	b := s.buf[0]
	s.buf = s.buf[1:]
	return b
}

// Method to check if the end of file has been reached
func (s *SimpleScanner) checkEof() {
	if s.eof {
		panic("EOF")
	}
}

// Method to read the next character
func (s *SimpleScanner) nextChar() byte {
	s.checkEof()
	b := s.read()
	s.checkEof()
	return b
}

// Method to read the next string
func (s *SimpleScanner) next() string {
	var b byte
	do {
		b = s.read()
		s.checkEof()
	} while (b == ' ' || b == '\n' || b == '\r' || b == '\t')
	sb := strings.Builder{}
	do {
		sb.WriteByte(b)
		b = s.read()
	} while (b != ' ' && b != '\n' && b != '\r' && b != '\t' && !s.eof)
	return sb.String()
}

// Method to read the next integer
func (s *SimpleScanner) nextInt() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

// Method to read the next long integer
func (s *SimpleScanner) nextLong() int64 {
	i, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

// Method to read the next double
func (s *SimpleScanner) nextDouble() float64 {
	i, err := strconv.ParseFloat(s.next(), 64)
	if err != nil {
		panic(err)
	}
	return i
}
