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
	scanner := NewSimpleScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	r := scanner.nextInt()
	d := scanner.nextInt()
	x := scanner.nextLong()
	for i := 0; i < 10; i++ {
		x = int64(r)*x - int64(d)
		writer.WriteString(strconv.FormatInt(x, 10) + "\n")
	}
	writer.Flush()
}

type SimpleScanner struct {
	reader *bufio.Reader
	eof    bool
}

func NewSimpleScanner(in io.Reader) *SimpleScanner {
	return &SimpleScanner{reader: bufio.NewReader(in)}
}

func (s *SimpleScanner) read() byte {
	for {
		b, err := s.reader.ReadByte()
		if err != nil {
			if err == io.EOF {
				s.eof = true
				return 0
			}
			panic(err)
		}
		return b
	}
}

func (s *SimpleScanner) checkEof() {
	if s.eof {
		panic("EOF")
	}
}

func (s *SimpleScanner) nextChar() byte {
	s.checkEof()
	b := s.read()
	s.checkEof()
	return b
}

func (s *SimpleScanner) next() string {
	b := s.nextChar()
	for b == ' ' || b == '\n' || b == '\t' {
		b = s.read()
	}
	var sb strings.Builder
	for b != ' ' && b != '\n' && b != '\t' && b != 0 {
		sb.WriteByte(b)
		b = s.read()
	}
	return sb.String()
}

func (s *SimpleScanner) nextInt() int {
	num, _ := strconv.Atoi(s.next())
	return num
}

func (s *SimpleScanner) nextLong() int64 {
	num, _ := strconv.ParseInt(s.next(), 10, 64)
	return num
}

func (s *SimpleScanner) nextDouble() float64 {
	num, _ := strconv.ParseFloat(s.next(), 64)
	return num
}

