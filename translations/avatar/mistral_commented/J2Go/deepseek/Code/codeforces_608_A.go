package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

type FastScanner struct {
	sc *bufio.Scanner
}

func NewFastScanner(r io.Reader) *FastScanner {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)
	return &FastScanner{sc: sc}
}

func (fs *FastScanner) next() string {
	fs.sc.Scan()
	return fs.sc.Text()
}

func (fs *FastScanner) nextLine() string {
	fs.sc.Scan()
	return fs.sc.Text()
}

func (fs *FastScanner) nextByte() byte {
	b, _ := strconv.ParseByte(fs.next())
	return b
}

func (fs *FastScanner) nextShort() int16 {
	s, _ := strconv.ParseInt(fs.next(), 10, 16)
	return int16(s)
}

func (fs *FastScanner) nextInt() int {
	i, _ := strconv.Atoi(fs.next())
	return i
}

func (fs *FastScanner) nextLong() int64 {
	l, _ := strconv.ParseInt(fs.next(), 10, 64)
	return l
}

func (fs *FastScanner) nextDouble() float64 {
	d, _ := strconv.ParseFloat(fs.next(), 64)
	return d
}

func main() {
	fs := NewFastScanner(os.Stdin)
	sc := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	n := fs.nextInt()

	for i := 0; i < n; i++ {
		f := fs.nextInt()
		t := fs.nextInt()

		max := 0

		if max < f+t {
			max = f + t
		}
	}

	writer.WriteString(fmt.Sprintf("%d\n", max))
	writer.Flush()
}

