package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := NewFastReader()
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n := in.nextInt()
	m := in.nextInt()
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	for i := 0; i < m; i++ {
		r := in.nextInt()
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c := in.nextInt()
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	answer := (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	if n%2 != 0 {
		mid := (n + 1) / 2
		if !bannedRows[mid] && !bannedCols[mid] {
			answer--
		}
	}

	fmt.Fprintln(out, answer)
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
	if !r.sc.Scan() {
		panic("failed to scan")
	}
	return r.sc.Text()
}

func (r *FastReader) nextInt() int {
	n, err := strconv.Atoi(r.next())
	if err != nil {
		panic(err)
	}
	return n
}

func (r *FastReader) nextLong() int64 {
	n, err := strconv.ParseInt(r.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return n
}

func (r *FastReader) nextDouble() float64 {
	n, err := strconv.ParseFloat(r.next(), 64)
	if err != nil {
		panic(err)
	}
	return n
}

func (r *FastReader) nextLine() string {
	line, err := r.sc.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(line, "\n")
}
