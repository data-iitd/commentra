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

func (r *FastReader) ReadInt() int {
	r.sc.Scan()
	num, _ := strconv.Atoi(r.sc.Text())
	return num
}

func (r *FastReader) ReadLong() int64 {
	r.sc.Scan()
	num, _ := strconv.ParseInt(r.sc.Text(), 10, 64)
	return num
}

func (r *FastReader) ReadString() string {
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
		y >>= 1
		x = (x * x) % mod
	}
	return res
}

type Pair struct {
	First  int64
	Second int64
}

func main() {
	in := NewFastReader()
	a := [4]int64{}
	for i := 0; i < 4; i++ {
		a[i] = in.ReadLong()
	}
	result := max(a[0]*a[2], max(a[1]*a[3], max(a[0]*a[3], a[1]*a[2])))
	fmt.Println(result)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

