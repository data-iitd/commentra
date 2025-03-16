package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[i])
	}
	b := make([][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		m := a[i]
		for j := 0; j < n; j++ {
			k := i - j
			if k < 0 {
				k += n
			}
			m = min(m, a[k])
			b[j][i] = m
		}
	}
	m := 1000000000000000
	for i := 0; i < n; i++ {
		m = min(m, sum(b[i])+x*i)
	}
	fmt.Println(m)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(a []int) int {
	s := 0
	for _, v := range a {
		s += v
	}
	return s
}

// 