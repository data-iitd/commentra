
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	scanner := NewSimpleScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	r := scanner.NextInt()
	d := scanner.NextInt()
	x := scanner.NextLong()
	for i := 0; i < 10; i++ {
		x = r*x - d
		fmt.Fprintln(writer, x)
	}
	writer.Flush()
}

type SimpleScanner struct {
	in     io.Reader
	buffer *bufio.Scanner
	eof    bool
}

func NewSimpleScanner(in io.Reader) *SimpleScanner {
	return &SimpleScanner{
		in:     in,
		buffer: bufio.NewScanner(in),
		eof:    false,
	}
}

func (s *SimpleScanner) NextChar() byte {
	if !s.buffer.Scan() {
		s.eof = true
		return 0
	}
	return s.buffer.Bytes()[0]
}

func (s *SimpleScanner) Next() string {
	for {
		b := s.NextChar()
		if s.eof || !isWhitespace(b) {
			break
		}
	}
	var sb []byte
	for {
		b := s.NextChar()
		if s.eof || isWhitespace(b) {
			break
		}
		sb = append(sb, b)
	}
	return string(sb)
}

func (s *SimpleScanner) NextInt() int {
	return strconv.Atoi(s.Next())
}

func (s *SimpleScanner) NextLong() int64 {
	return strconv.ParseInt(s.Next(), 10, 64)
}

func (s *SimpleScanner) NextDouble() float64 {
	return strconv.ParseFloat(s.Next(), 64)
}

func isWhitespace(b byte) bool {
	return b == ' ' || b == '\n' || b == '\t' || b == '\r'
}

