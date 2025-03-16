<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Declare global arrays to be used in the quicksort algorithm
var low [200000]int
var high [200000]int
var a [200000]int

// Partition function to rearrange elements in array 'a' based on values in array 'b'
func part(a []int, b []int, l int, r int) int {
	var i, j, x, t int

	i = l - 1
	j = r
	x = b[r]

	for {
		for b[i+1] < x {
			i++
		}
		for i < j && x < b[j-1] {
			j--
		}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
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
			low[sp+1] = l
			high[sp+1] = v - 1
			sp += 2
		} else {
			low[sp] = l
			high[sp] = v - 1
			low[sp+1] = v + 1
			high[sp+1] = r
			sp += 2
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
	fmt.Scanf("%d %d", &n, &m)

	// Read the pairs of integers into arrays 'a' and 'b'
	for i = 0; i < m; i++ {
		fmt.Scanf("%d %d", &a[i], &b[i])
	}

	// Sort the pairs using the quicksort function
	quicksort(a[:m], b[:m], m)

	// Count the number of unique intervals
	t = 0
	for i = 0; i < m; i++ {
		if t <= a[i] {
			t = b[i]
			cnt++
		}
	}

	// Print the count of unique intervals
	fmt.Printf("%d\n", cnt)
}

