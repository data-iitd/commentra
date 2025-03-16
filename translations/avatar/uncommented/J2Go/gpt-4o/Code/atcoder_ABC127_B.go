package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := NewSimpleScanner(os.Stdin)
	r := scanner.NextInt()
	d := scanner.NextInt()
	x := scanner.NextLong()

	for i := 0; i < 10; i++ {
		x = r*x - d
		fmt.Println(x)
	}
}

type SimpleScanner struct {
	scanner *bufio.Scanner
}

func NewSimpleScanner(r *os.File) *SimpleScanner {
	return &SimpleScanner{
		scanner: bufio.NewScanner(r),
	}
}

func (s *SimpleScanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *SimpleScanner) NextInt() int {
	val, _ := strconv.Atoi(s.Next())
	return val
}

func (s *SimpleScanner) NextLong() int64 {
	val, _ := strconv.ParseInt(s.Next(), 10, 64)
	return val
}

func (s *SimpleScanner) NextDouble() float64 {
	val, _ := strconv.ParseFloat(s.Next(), 64)
	return val
}

// Note: Error handling is omitted for brevity. In production code, you should handle errors appropriately.
