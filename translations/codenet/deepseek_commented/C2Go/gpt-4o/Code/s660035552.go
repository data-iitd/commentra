package main

import (
	"fmt"
)

var low [200000]int
var high [200000]int

// Partition function to rearrange elements in array 'a' based on values in array 'b'
func part(a []int, b []int, l int, r int) int {
	i := l - 1
	j := r
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
	var sp int
	low[0] = 0
	high[0] = n - 1
	sp = 1

	for sp > 0 {
		sp--
		l := low[sp]
		r := high[sp]

		if l >= r {
			continue
		}

		// Partition the array and get the pivot index
		v := part(a, b, l, r)

		// Push the sub-ranges onto the stack based on the pivot position
		if v-l < r-v {
			low[sp] = v + 1
			high[sp] = r
			sp++
			low[sp] = l
			high[sp] = v - 1
			sp++
		} else {
			low[sp] = l
			high[sp] = v - 1
			sp++
			low[sp] = v + 1
			high[sp] = r
			sp++
		}
	}
}

func main() {
	var n, m int
	var cnt int
	var t int

	// Read the number of elements and the number of pairs
	fmt.Scan(&n, &m)

	// Create slices for pairs of integers
	a := make([]int, m)
	b := make([]int, m)

	// Read the pairs of integers into arrays 'a' and 'b'
	for i := 0; i < m; i++ {
		fmt.Scan(&a[i], &b[i])
	}

	// Sort the pairs using the quicksort function
	quicksort(a, b, m)

	// Count the number of unique intervals
	t = 0
	for i := 0; i < m; i++ {
		if t <= a[i] {
			t = b[i]
			cnt++
		}
	}

	// Print the count of unique intervals
	fmt.Println(cnt)
}

// <END-OF-CODE>
