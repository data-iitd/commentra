package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	m := n * (n + 1) / 4
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
		c := min(b)
		for i := 1; i <= n; i++ {
			b[i] -= c
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
			t[0] = mid
		} else {
			t[1] = mid
		}
	}
	fmt.Println(_a[t[1]])
}

func min(a []int) int {
	m := a[0]
	for _, x := range a[1:] {
		if x < m {
			m = x
		}
	}
	return m
}

func max(a []int) int {
	m := a[0]
	for _, x := range a[1:] {
		if x > m {
			m = x
		}
	}
	return m
}

// 