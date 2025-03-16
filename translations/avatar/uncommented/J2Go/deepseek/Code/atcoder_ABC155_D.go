package main

import (
	"fmt"
	"math"
	"sort"
)

const mod = 1e9 + 7

var DX = []int{-1, 0, 1, 0}
var DY = []int{0, -1, 0, 1}

func main() {
	var n int
	var k int64
	fmt.Scan(&n, &k)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
	INF := int64(math.Pow(10, 18)) + 1
	l, r := int64(-INF), int64(INF)
	for l+1 < r {
		c := (l + r) / 2
		if check(c, a, n, k) {
			l = c
		} else {
			r = c
		}
	}
	fmt.Println(l)
}

func check(x int64, a []int64, n int, k int64) bool {
	tot := int64(0)
	for i := 0; i < n; i++ {
		now := a[i]
		l, r := 0, n
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
	}
	return tot/2 < k
}

