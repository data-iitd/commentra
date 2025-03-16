
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Declare global arrays to be used in the quicksort algorithm
var low [200000]int
var high [200000]int
var a [200000]int
var b [200000]int

// Partition function to rearrange elements in array 'a' based on values in array 'b'
func part(a []int, b []int, l int, r int) int {
	var i, j, x, t int

	i = l - 1
	j = r
	x = b[r]

	for {
		for b[++i] < x {
		}
		for i < --j && x < b[j] {
		}

		if i >= j {
			break
		}

		// Swap elements in array 'a'
		t = a[i]
		a[i] = a[j]
		a[j] = t
		// Swap elements in array 'b'
		t = b[i]
		b[i] = b[j]
		b[j] = t
	}

	// Swap elements in array 'a' and 'b' to place pivot in the correct position
	t = a[i]
	a[i] = a[r]
	a[r] = t
	t = b[i]
	b[i] = b[r]
	b[r] = t
	return i
}

// Quicksort function to sort arrays 'a' and 'b' based on values in array 'b'
func quicksort(a []int, b []int, n int) {
	var l, r, v int
	var sp int

	// Initialize the stack with the first range to be sorted
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

		// Partition the array and get the pivot index
		v = part(a, b, l, r)

		// Push the sub-ranges onto the stack based on the pivot position
		if v-l < r-v {
			low[sp] = v + 1
			high[sp] = r
			low[sp] = l
			high[sp] = v - 1
			sp++
		} else {
			low[sp] = l
			high[sp] = v - 1
			low[sp] = v + 1
			high[sp] = r
			sp++
		}
	}
}

func main() {
	var n, m int
	var i int
	var a [100006]int
	var b [100006]int
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

