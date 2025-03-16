package main

import (
	"fmt"
)

// Declare global arrays to be used in the quicksort algorithm
var low [200000]int
var high [200000]int
var a [200000]int

// Partition function to rearrange elements in array 'a' based on values in array 'b'
func part(a []int, b []int, l, r int) int {
	i, j, x := l-1, r, b[r]
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
		// Swap elements in array 'a'
		a[i], a[j] = a[j], a[i]
		// Swap elements in array 'b'
		b[i], b[j] = b[j], b[i]
	}
	// Swap elements in array 'a' and 'b' to place pivot in the correct position
	a[i], a[r] = a[r], a[i]
	b[i], b[r] = b[r], b[i]
	return i
}

// Quicksort function to sort arrays 'a' and 'b' based on values in array 'b'
func quicksort(a []int, b []int, n int) {
	l, r, v := 0, n-1, 0
	sp := 0
	// Initialize the stack with the first range to be sorted
	low[sp], high[sp] = l, r
	sp++
	for sp > 0 {
		sp--
		l, r = low[sp], high[sp]
		if l >= r {
			continue
		}
		// Partition the array and get the pivot index
		v = part(a, b, l, r)
		// Push the sub-ranges onto the stack based on the pivot position
		if v-l < r-v {
			low[sp], high[sp] = v+1, r
			low[sp+1], high[sp+1] = l, v-1
			sp += 2
		} else {
			low[sp], high[sp] = l, v-1
			low[sp+1], high[sp+1] = v+1, r
			sp += 2
		}
	}
}

func main() {
	var n, m int
	var i int
	var a = [100006]int{}
	var b = [100006]int{}
	var cnt int
	var t int

	// Read the number of elements and the number of pairs
	fmt.Scan(&n, &m)

	// Read the pairs of integers into arrays 'a' and 'b'
	for i = 0; i < m; i++ {
		fmt.Scan(&a[i], &b[i])
	}

	// Sort the pairs using the quicksort function
	quicksort(a[:], b[:], m)

	// Count the number of unique intervals
	t = 0
	for i = 0; i < m; i++ {
		if t <= a[i] {
			t = b[i]
			cnt++
		}
	}

	// Print the count of unique intervals
	fmt.Println(cnt)
}

