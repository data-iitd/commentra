package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

const BUFFER_SIZE = 1024

type SimpleScanner struct {
	in   *bufio.Reader
	buf  []byte
	eof  bool
}

func NewSimpleScanner(in io.Reader) *SimpleScanner {
	return &SimpleScanner{in: bufio.NewReader(in)}
}

func (s *SimpleScanner) read() byte {
	if len(s.buf) == 0 {
		var err error
		s.buf, err = s.in.ReadBytes('\n')
		if err != nil {
			if err == io.EOF {
				s.eof = true
				return 0
			}
			panic(err)
		}
	}
	b := s.buf[0]
	s.buf = s.buf[1:]
	return b
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
	var sb []byte
	b := s.read()
	for b != 0 {
		sb = append(sb, b)
		b = s.read()
	}
	return string(sb)
}

func (s *SimpleScanner) nextInt() int {
	i, err := strconv.Atoi(s.next())
	if err != nil {
		panic(err)
	}
	return i
}

func (s *SimpleScanner) nextLong() int64 {
	i, err := strconv.ParseInt(s.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

func main() {
	scanner := NewSimpleScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	r := scanner.nextInt()
	d := scanner.nextInt()
	x := scanner.nextLong()

	for i := 0; i < 10; i++ {
		x = int64(r)*x - int64(d)
		writer.WriteString(fmt.Sprintf("%d\n", x))
	}

	writer.Flush()
}

