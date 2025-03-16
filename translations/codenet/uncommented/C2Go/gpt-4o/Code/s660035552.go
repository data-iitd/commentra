package main

import (
	"fmt"
)

var low [200000]int
var high [200000]int

func part(a []int, b []int, l int, r int) int {
	i, j := l-1, r
	x := b[r]

	for {
		for i++; b[i] < x; i++ {
		}
		for i < j && x < b[j] {
			j--
		}

		if i >= j {
			break
		}

		// Swap a[i] and a[j]
		a[i], a[j] = a[j], a[i]
		// Swap b[i] and b[j]
		b[i], b[j] = b[j], b[i]
	}

	// Swap a[i] and a[r]
	a[i], a[r] = a[r], a[i]
	// Swap b[i] and b[r]
	b[i], b[r] = b[r], b[i]
	return i
}

func quicksort(a []int, b []int, n int) {
	l, r, v := 0, 0, 0
	sp := 1

	low[0] = 0
	high[0] = n - 1

	for sp > 0 {
		sp--
		l = low[sp]
		r = high[sp]

		if l >= r {
			continue
		}

		v = part(a, b, l, r)

		if v-l < r-v {
			low[sp] = v + 1
			high[sp] = r
			sp++
			low[sp] = l
			high[sp] = v - 1
		} else {
			low[sp] = l
			high[sp] = v - 1
			sp++
			low[sp] = v + 1
			high[sp] = r
		}
	}
}

func main() {
	var n, m int
	var cnt int
	var t int

	fmt.Scan(&n, &m)

	a := make([]int, m)
	b := make([]int, m)

	for i := 0; i < m; i++ {
		fmt.Scan(&a[i], &b[i])
	}

	quicksort(a, b, m)

	t = 0
	for i := 0; i < m; i++ {
		if t <= a[i] {
			t = b[i]
			cnt++
		}
	}

	fmt.Println(cnt)
}

// <END-OF-CODE>
