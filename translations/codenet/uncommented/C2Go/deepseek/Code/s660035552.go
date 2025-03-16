package main

import (
	"fmt"
)

var low [200000]int
var high [200000]int
var a [200000]int

func part(a []int, b []int, l, r int) int {
	i, j := l-1, r
	x := b[r]
	for {
		for a[i+1] < x {
			i++
		}
		for j > l && x < b[j-1] {
			j--
		}
		if i >= j {
			break
		}
		a[i], a[j] = a[j], a[i]
		b[i], b[j] = b[j], b[i]
	}
	a[i], a[r] = a[r], a[i]
	b[i], b[r] = b[r], b[i]
	return i
}

func quicksort(a []int, b []int, n int) {
	sp := 0
	low[0], high[0] = 0, n-1
	for sp >= 0 {
		l, r := low[sp], high[sp]
		sp--
		if l >= r {
			continue
		}
		v := part(a[:], b[:], l, r)
		if v-l < r-v {
			sp++
			low[sp], high[sp] = v+1, r
			sp++
			low[sp], high[sp] = l, v-1
		} else {
			sp++
			low[sp], high[sp] = l, v-1
			sp++
			low[sp], high[sp] = v+1, r
		}
	}
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := [100006]int{}
	b := [100006]int{}
	for i := 0; i < m; i++ {
		fmt.Scan(&a[i], &b[i])
	}
	quicksort(a[:], b[:], m)
	t := 0
	cnt := 0
	for i := 0; i < m; i++ {
		if t <= a[i] {
			t = b[i]
			cnt++
		}
	}
	fmt.Println(cnt)
}

