
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Initialize low and high arrays for quicksort
var low [200000]int
var high [200000]int

// Array 'a' to store elements after sorting
var a [200000]int

// Array 'b' to store elements for quicksort partitioning
var b [200000]int

// Function to partition the array using quicksort algorithm
func part(a []int, b []int, l int, r int) int {
	var i, j, x, t int // Initialize variables

	i = l - 1 // Initialize index 'i' for smaller elements
	j = r   // Initialize index 'j' for greater elements

	x = b[r] // Set pivot as last element

	for { // While loop for partitioning
		for b[i+1] < x {
			i++ // Move 'i' to next smaller element
		}
		for i < j && x < b[j-1] {
			j-- // Move 'j' to previous greater element
		}
		if i >= j {
			break // If 'i' and 'j' meet, partitioning is done
		}
		t = a[i]
		a[i] = a[j]
		a[j] = t
		t = b[i]
		b[i] = b[j]
		b[j] = t
	}

	t = a[i]
	a[i] = a[r]
	a[r] = t
	t = b[i]
	b[i] = b[r]
	b[r] = t
	return i // Return index of pivot
}

// Function to perform quicksort on the array 'a'
func quicksort(a []int, b []int, n int) {
	var l, r, v int // Initialize variables
	var sp int       // Stack pointer

	low[0] = 0 // Initialize 'low' stack with base index 0
	high[0] = n - 1 // Initialize 'high' stack with top index 'n-1'
	sp = 1 // Initialize stack pointer

	for sp > 0 { // While stack is not empty
		sp-- // Decrement stack pointer
		l = low[sp] // Get base index 'l' from stack
		r = high[sp] // Get top index 'r' from stack

		if l >= r { // If base and top indices are same, no need to partition
			continue // Skip this iteration
		}

		v = part(a, b, l, r) // Partition the array

		if v-l < r-v { // If partitioning moved pivot to left, swap 'low' and 'high' indices
			low[sp] = v + 1
			high[sp] = r
			low[sp+1] = l
			high[sp+1] = v - 1
		} else { // If partitioning moved pivot to right, swap 'low' and 'high' indices in reverse order
			low[sp] = l
			high[sp] = v - 1
			low[sp+1] = v + 1
			high[sp+1] = r
		}
	}
}

// Main function to read input and call quicksort
func main() {
	var n, m int // Initialize variables
	var i int     // Initialize loop variable
	var a [100006]int
	var b [100006]int
	var cnt int
	var t int

	fmt.Scanf("%d %d", &n, &m) // Read number of elements 'n' and queries'm'

	for i = 0; i < m; i++ {
		fmt.Scanf("%d %d", &a[i], &b[i]) // Read elements and their corresponding queries
	}

	quicksort(a[:m], b[:m], m) // Call quicksort function to sort elements

<<<<<<< HEAD
	t = 0 // Initialize counter to 0
	for i = 0; i < m; i++ { // Iterate through sorted elements
		if t <= a[i] { // If current element is greater than previous element, increment counter
			t = b[i] // Set current query as new temporary storage
			cnt++ // Increment counter
=======
	t = 0
	for i = 0; i < m; i++ { // Iterate through sorted elements
		if t <= a[i] { // If current element is greater than previous element, increment counter
			t = b[i] // Set current query as new temporary storage
			cnt++
>>>>>>> 98c87cb78a (data updated)
		}
	}

	fmt.Printf("%d\n", cnt) // Print the number of unique queries
}

