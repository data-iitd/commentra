package main

import (
	"fmt"
)

// Initialize low and high arrays for quicksort
var low [200000]int
var high [200000]int

// Array 'a' to store elements after sorting
var a [200000]int

// Array 'b' to store elements for quicksort partitioning
var b [200000]int

// Function to partition the array using quicksort algorithm
func part(a []int, b []int, l, r int) int {
	i, j := l-1, r
	x := b[r]

	for {
		for b[i+1] < x {
			i++
		}
		for j > l && x < b[j] {
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

// Function to perform quicksort on the array 'a'
func quicksort(a []int, b []int, n int) {
	l, r, v := 0, 0, 0
	sp := 0

	low[0] = 0
	high[0] = n - 1
	sp = 1

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
			low[sp+1] = l
			high[sp+1] = v - 1
			sp++
		} else {
			low[sp] = l
			high[sp] = v - 1
			low[sp+1] = v + 1
			high[sp+1] = r
			sp++
		}
	}
}

// Main function to read input and call quicksort
func main() {
	var n, m int
	fmt.Scan(&n, &m)

	for i := 0; i < m; i++ {
		fmt.Scan(&a[i], &b[i])
	}

	quicksort(a[:m], b[:m], m)

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

