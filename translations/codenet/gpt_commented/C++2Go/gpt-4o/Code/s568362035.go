package main

import (
	"fmt"
)

const MAXN = 1E5 + 10 // Define a constant for the maximum size of arrays

var n, m, Q int // Declare variables for number of elements, maximum value, and number of queries
var a [MAXN]int // Array to store the queries
var b [MAXN]int // Array b to store unique values
var id [MAXN]int // Array to map values to their indices
var vis [MAXN]bool // Boolean array to track which values have been seen
var cnt [MAXN]int // Array to count occurrences of values

func main() {
	// Read the number of elements (n) and the maximum value (m)
	fmt.Scan(&n, &m)
	// Read the number of queries (Q)
	fmt.Scan(&Q)

	// Read the queries into array a
	for i := 1; i <= Q; i++ {
		fmt.Scan(&a[i])
	}

	// Process the queries to fill array b with unique values from a
	k := 0
	for j := Q; j > 0; j-- {
		if !vis[a[j]] { // If the value has not been seen yet
			k++
			b[k] = a[j]
			vis[a[j]] = true // Add it to b and mark it as seen
		}
	}

	// Fill the remaining positions in b with the largest unused values up to m
	for j, i := m, m; i > 0; i-- {
		if !vis[i] { // If the value i has not been seen
			b[j] = i // Add it to b
			j--
		}
	}

	// Map each value in b to its index in id
	for i := 1; i <= m; i++ {
		id[b[i]] = i
	}

	flag := true // Initialize a flag to track the validity of the sequence
	cnt[0] = n   // Initialize the count of the first value to n

	// Process the queries in reverse order
	for i := Q; i > 0; i-- {
		t := id[a[i]] // Get the index of the current query value
		if cnt[t-1] > 0 { // If there are available counts for the previous index
			cnt[t-1]-- // Decrease the count for the previous index
			cnt[t]++   // Increase the count for the current index
			vis[t] = true // Mark the current index as seen
		} else if !vis[t] { // If the current index has not been seen
			flag = false // Set the flag to false, indicating an invalid sequence
			break // Exit the loop
		}
	}

	// Find the first index l where count is non-zero
	l := 0
	for cnt[l] == 0 {
		l++
	}

	// Check if the remaining values in b are in increasing order
	for i := l + 1; i < m; i++ {
		flag = flag && (b[i] < b[i+1]) // Update flag based on the order of values in b
	}

	// Output the result based on the flag
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
