package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = int(1e9 + 7)

var DX = []int{-1, 0, 1, 0}
var DY = []int{0, -1, 0, 1}

var n int
var k int64
var a []int64

func main() {
	var fs = newScanner()

	n = fs.Int()
	k = fs.Int64()
	a = make([]int64, n)

	for i := 0; i < n; i++ {
		a[i] = fs.Int64()
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	INF := int64(math.Pow(10, 18)) + 1
	l := int64(-INF)
	r := int64(INF)

	for l+1 < r {
		c := (l + r) / 2
		if check(c) {
			l = c
		} else {
			r = c
		}
	}

	fmt.Println(l)
}

func check(x int64) bool {
	tot := int64(0)

	for i := 0; i < n; i++ {
		now := a[i]
		l := 0
		r := n

		if now >= 0 {
			for l < r {
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(l)
		} else {
			for l < r {
				c := (l + r) / 2
				if now*a[c] >= x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(n - l)
		}

		if now*now < x {
			tot--
		}

		if tot/2 < k {
			return true
		}
	}

	return false
}

type scanner struct {
	buf []byte
	pos int
}

func newScanner() *scanner {
	buf := make([]byte, 0, 1024)
	buf = append(buf, []byte(fmt.Sprintf("%d %d", n, k))...)
	for _, v := range a {
		buf = append(buf, []byte(fmt.Sprintf(" %d", v))...)
	}
	return &scanner{buf: buf}
}

func (s *scanner) Int() int {
	v, _ := strconv.Atoi(string(s.buf[s.pos : s.pos+1]))
	s.pos++
	return v
}

func (s *scanner) Int64() int64 {
	v, _ := strconv.ParseInt(string(s.buf[s.pos:]), 10, 64)
	s.pos += int(math.Log10(float64(v))) + 1
	return v
}
