package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := NewFastReader()
	pw := bufio.NewWriter(os.Stdout)
	defer pw.Flush()

	x := sc.nextInt()
	count := 0
	tmp := x
	for x != 360 {
		x = x + tmp
		if x > 360 {
			x = x - 360
		}
		count++
	}
	fmt.Fprintln(pw, count)
}

type FastReader struct {
	sc *bufio.Scanner
}

func NewFastReader() *FastReader {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return &FastReader{sc: sc}
}

func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

func (r *FastReader) nextInt() int {
	i, _ := strconv.Atoi(r.next())
	return i
}

func (r *FastReader) nextLong() int64 {
	i, _ := strconv.ParseInt(r.next(), 10, 64)
	return i
}

func (r *FastReader) nextDouble() float64 {
	f, _ := strconv.ParseFloat(r.next(), 64)
	return f
}

func (r *FastReader) nextLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

