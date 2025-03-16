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
	in := NewFastScanner(os.Stdin)
	sc := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	s, _ := strconv.Atoi(sc.Text())
	max := 0

	for i := 0; i < n; i++ {
		sc.Scan()
		f, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		t, _ := strconv.Atoi(sc.Text())
		if max < f+t {
			max = f + t
		}
	}

	if max > s {
		fmt.Fprintln(out, max)
	} else {
		fmt.Fprintln(out, s)
	}
	out.Flush()
}

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
	line, _ := fs.sc.ReadString('\n')
	return strings.TrimSpace(line)
}

func (fs *FastScanner) nextByte() byte {
	b, _ := strconv.Atoi(fs.next())
	return byte(b)
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

func (fs *FastScanner) nextFloat() float32 {
	f, _ := strconv.ParseFloat(fs.next(), 32)
	return float32(f)
}

func (fs *FastScanner) nextDouble() float64 {
	d, _ := strconv.ParseFloat(fs.next(), 64)
	return d
}
