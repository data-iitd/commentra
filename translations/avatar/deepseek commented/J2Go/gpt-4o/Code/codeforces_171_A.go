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
	num, _ := strconv.Atoi(fr.Next())
	return num
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
	n := fr.NextInt() // Read the first integer
	m := fr.NextInt() // Read the second integer
	t := reverse(m)   // Reverse the second integer
	fmt.Println(t + n) // Print the sum of the reversed integer and the first integer
}

// <END-OF-CODE>
