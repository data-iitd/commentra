package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	m := n * (n + 1) / 2
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	d := make(map[int]int)
	_a := make([]int, 0)
	for _, x := range a {
		if _, ok := d[x]; !ok {
			d[x] = len(d)
			_a = append(_a, x)
		}
	}
	for i, x := range a {
		a[i] = d[x]
	}
	check := func(X int) bool {
		b := make([]int, n+1)
		for i, x := range a {
			b[i+1] = (x >= X) * 2 - 1
		}
		for i := 1; i <= n; i++ {
			b[i] += b[i-1]
		}
		c := math.MinInt32
		for _, x := range b {
			if x < c {
				c = x
			}
		}
		for i, x := range b {
			b[i] = x - c
		}
		bit := make([]int, max(b)+2)
		ans := 0
		for _, x := range b {
			ans += bit[x+1]
			bit[x+1]++
		}
		return ans >= m
	}
	t := []int{len(_a), 0}
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(mid) {
			t[1] = mid
		} else {
			t[0] = mid
		}
	}
	sort.Ints(_a)
	fmt.Println(_a[t[1]])
}

func max(a []int) int {
	m := math.MinInt32
	for _, x := range a {
		if x > m {
			m = x
		}
	}
	return m
}

