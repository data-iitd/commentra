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
	n := in.nextInt()
	left := make(map[int]bool)
	answer := make([]int, n)
	for i := 0; i < n; i++ {
		left[i] = true
	}
	q := in.nextInt()
	for q > 0 {
		q--
		l := in.nextInt() - 1
		r := in.nextInt() - 1
		win := in.nextInt() - 1
		for k := range left {
			if k >= l && k <= r {
				answer[k] = win
				delete(left, k)
			}
		}
		answer[win] = 0
		left[win] = true
	}
	var ans strings.Builder
	for i := 0; i < n; i++ {
		ans.WriteString(strconv.Itoa(answer[i]))
		ans.WriteString("")
	}
	fmt.Println(ans.String())
}

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
