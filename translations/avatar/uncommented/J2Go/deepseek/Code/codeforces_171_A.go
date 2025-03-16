package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	sc *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

func (r *FastReader) nextInt() int {
	n, _ := strconv.Atoi(r.next())
	return n
}

func (r *FastReader) nextLong() int64 {
	n, _ := strconv.ParseInt(r.next(), 10, 64)
	return n
}

func (r *FastReader) nextDouble() float64 {
	n, _ := strconv.ParseFloat(r.next(), 64)
	return n
}

func (r *FastReader) nextLine() string {
	r.sc.Scan()
	return r.sc.Text()
}

func reverse(n int) int {
	if n < 10 {
		return n * 10
	}
	var r int
	for t := n; t > 0; t /= 10 {
		r = r*10 + t%10
	}
	return r
}

func main() {
	sc := NewFastReader()
	n := sc.nextInt()
	m := sc.nextInt()
	t := reverse(m)
	fmt.Println(t + n)
}

