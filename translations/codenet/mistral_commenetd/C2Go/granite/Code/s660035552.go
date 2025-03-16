

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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
	j = r     // Initialize index 'j' for greater elements

	x = b[r] // Set pivot as last element

	for { // While loop for partitioning
		for b[++i] < x {
		}
		for i < --j && x < b[j] {
		}

		if i >= j {
			break // If 'i' and 'j' meet, partitioning is done
		}

		t = a[i] // Swap elements in 'a' array
		a[i] = a[j]
		a[j] = t

		t = b[i] // Swap elements in 'b' array
		b[i] = b[j]
		b[j] = t
	}

	t = a[i] // Swap pivot with last element in 'a' array
	a[i] = a[r]
	a[r] = t

	t = b[i] // Swap pivot with last element in 'b' array
	b[i] = b[r]
	b[r] = t

	return i // Return index of pivot
}

// Function to perform quicksort on the array 'a'
func quicksort(a []int, b []int, n int) {
	var l, r, v int // Initialize variables
	var sp int // Initialize stack pointer

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
			low[sp] = l
			high[sp] = v - 1
		} else { // If partitioning moved pivot to right, swap 'low' and 'high' indices in reverse order
			low[sp] = l
			high[sp] = v - 1
			low[sp] = v + 1
			high[sp] = r
		}
	}
}

// Main function to read input and call quicksort
func main() {
	var n, m int // Initialize variables
	var i int // Initialize loop variable
	var a [100006]int // Initialize array 'a' of size 100006
	var b [100006]int // Initialize array 'b' of size 100006
	var cnt int // Initialize counter for unique elements
	var t int // Initialize variable for temporary storage

	scanner := bufio.NewScanner(os.Stdin) // Create a new scanner to read input from standard input

	fmt.Fscanf(scanner, "%d %d\n", &n, &m) // Read number of elements 'n' and queries'm'

	for i = 0; i < m; i++ { // Iterate through queries
		fmt.Fscanf(scanner, "%d %d\n", &a[i], &b[i]) // Read elements and their corresponding queries
	}

	quicksort(a[:], b[:], m) // Call quicksort function to sort elements

	t = 0 // Initialize counter to 0
	for i = 0; i < m; i++ { // Iterate through sorted elements
		if t <= a[i] { // If current element is greater than previous element, increment counter
			t = b[i] // Set current query as new temporary storage
			cnt++ // Increment counter
		}
	}

	fmt.Println(cnt) // Print the number of unique queries

	// 