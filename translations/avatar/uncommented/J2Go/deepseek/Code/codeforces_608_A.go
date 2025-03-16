package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := NewFastScanner()
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	o := bufio.NewWriter(os.Stdout)

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
		fmt.Fprintln(o, max)
	} else {
		fmt.Fprintln(o, s)
	}
	o.Flush()
}

type FastScanner struct {
	sc *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	sc := bufio.NewScanner(os.Stdin)
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

func (fs *FastScanner) nextDouble() float64 {
	d, _ := strconv.ParseFloat(fs.next(), 64)
	return d
}
