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
	num, _ := strconv.Atoi(r.next())
	return num
}

func (r *FastReader) nextLong() int64 {
	num, _ := strconv.ParseInt(r.next(), 10, 64)
	return num
}

func (r *FastReader) nextDouble() float64 {
	num, _ := strconv.ParseFloat(r.next(), 64)
	return num
}

func (r *FastReader) nextLine() string {
	r.sc.Scan()
	return r.sc.Text()
}

func modPower(x, y, mod int) int {
	res := 1
	x %= mod
	if x == 0 {
		return 0
	}
	for y > 0 {
		if y%2 == 1 {
			res = (res * x) % mod
		}
		y = y >> 1
		x = (x * x) % mod
	}
	return res
}

type pair struct {
	first  int64
	second int64
}

func main() {
	in := NewFastReader()
	var a [4]int64
	for i := 0; i < 4; i++ {
		a[i] = in.nextLong()
	}
	fmt.Println(max(a[0]*a[2], max(a[1]*a[3], max(a[0]*a[3], a[1]*a[2]))))
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

