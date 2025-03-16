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
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	n := sc.nextInt()
	a := make([]int, 33)
	for i := 0; i < n; i++ {
		a[rec(sc.nextInt())]++
	}
	var answer float64
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * float64(a[i]-1)
		answer += summ
	}
	fmt.Fprintln(out, int64(answer))
}

func rec(x int) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if (x & (1 << k)) != 0 {
			answer++
		}
	}
	return answer
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
	if !r.sc.Scan() {
		panic("failed to scan")
	}
	return r.sc.Text()
}
