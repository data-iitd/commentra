package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	scanner *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)}
}

func (fr *FastReader) Next() string {
	fr.scanner.Scan()
	return fr.scanner.Text()
}

func (fr *FastReader) NextInt() int {
	val, _ := strconv.Atoi(fr.Next())
	return val
}

func reverse(n int) int {
	if n < 10 {
		return n * 10
	}
	r := 0
	for t := n; t > 0; t /= 10 {
		r = r*10 + t%10
	}
	return r
}

func main() {
	fr := NewFastReader()
	n := fr.NextInt()
	m := fr.NextInt()
	t := reverse(m)
	fmt.Println(t + n)
}

// <END-OF-CODE>
