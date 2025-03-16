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
		for {
			if _, ok := left[in.ceiling(l)]; !ok {
				break
			}
			curr := in.ceiling(l)
			answer[curr] = win
			delete(left, curr)
		}
		answer[win] = -1
		left[win] = true
	}
	var ans strings.Builder
	for i := 0; i < n; i++ {
		ans.WriteString(strconv.Itoa(answer[i]) + "")
	}
	fmt.Println(ans.String())
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
		return ""
	}
	return r.sc.Text()
}

func (r *FastReader) nextInt() int {
	val, _ := strconv.Atoi(r.next())
	return val
}

func (r *FastReader) nextLong() int64 {
	val, _ := strconv.ParseInt(r.next(), 10, 64)
	return val
}

func (r *FastReader) nextDouble() float64 {
	val, _ := strconv.ParseFloat(r.next(), 64)
	return val
}

func (r *FastReader) nextLine() string {
	if !r.sc.Scan() {
		return ""
	}
	return r.sc.Text()
}

func (r *FastReader) ceiling(l int) int {
	for i := l; i < len(answer); i++ {
		if left[i] {
			return i
		}
	}
	return -1
}
