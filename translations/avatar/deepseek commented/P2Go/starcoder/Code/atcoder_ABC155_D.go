package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to count valid pairs
func countPairs(A []int, x int) int {
	// Initializing the total count of valid pairs
	tot := 0

	// Counting valid pairs for each element in A
	for i := 0; i < len(A); i++ {
		if A[i] < 0 {
			l := -1
			r := len(A)
			for l+1 < r {
				c := (l + r) / 2
				if A[i]*A[c] < x {
					r = c
				} else {
					l = c
			}
			tot += len(A) - r // Updating the total count for negative A[i]
		} else {
			l := -1
			r := len(A)
			for l+1 < r {
				c := (l + r) / 2
				if A[i]*A[c] < x {
					l = c
				} else {
					r = c
			}
			tot += r // Updating the total count for non-negative A[i]
		}
		if A[i]*A[i] < x {
			tot -= 1 // Adjusting for the pair (i, i) if necessary
	}
	tot /= 2 // Dividing by 2 to correct for double-counting pairs

	return tot
}

// Main function
func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &N, &K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	// Sorting the list A
	sort.Ints(A)

	// Binary search setup
	ll := -1000000000 - 1 // Lower limit initialized to a very small number
	rr := 1000000000 + 1 // Upper limit initialized to a very large number

	// Binary search execution
	for ll+1 < rr {
		x := (ll + rr) / 2 // Calculating the midpoint of the current range
		tot := countPairs(A, x) // Counting valid pairs

		// Adjusting the search range based on the total count
		if tot < K {
			ll = x
		} else {
			rr = x
	}
	fmt.Println(ll) // Output the result
}

