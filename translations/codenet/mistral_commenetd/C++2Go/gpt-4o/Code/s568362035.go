package main

import (
	"fmt"
)

const MAXN = 1E5 + 10 // Maximum size of the input

var (
	n, m, Q int                     // n: number of elements in the array, m: size of the result array, Q: number of queries
	a       [MAXN]int               // Input array
	b       [MAXN]int               // Output array
	id      [MAXN]int               // Index array
	vis     [MAXN]bool              // Visited flag array
	cnt     [MAXN]int               // Counter array
)

func main() {
	// Read input
	fmt.Scan(&n, &m)
	fmt.Scan(&Q)
	for i := 1; i <= Q; i++ {
		fmt.Scan(&a[i]) // Read queries
	}

	// Initialize variables
	k := 0
	for j := Q; j > 0; j-- {
		// Find unvisited elements and add them to the output array
		if !vis[a[j]] {
			k++
			b[k] = a[j] // Add the element to the output array
			vis[a[j]] = true // Mark it as visited
		}
	}

	// Fill the output array with the remaining unvisited elements
	for j, i := m, m; i > 0; i-- {
		if !vis[i] {
			b[j] = i // Add the element to the output array
			j--
		}
	}

	// Assign indices to the output array elements
	for i := 1; i <= m; i++ {
		id[b[i]] = i // Assign index i to the element b[i]
	}

	// Process queries
	flag := true
	cnt[0] = n // Initialize counter array with the number of elements in the input array
	for i := Q; i > 0; i-- {
		t := id[a[i]] // Get the index of the element a[i] in the output array
		if cnt[t-1] > 0 { // If the previous element is still present in the input array
			cnt[t-1]-- // Decrease its counter
			cnt[t]++   // Increase the counter of the current element
			vis[t] = true // Mark it as visited
		} else if !vis[t] { // If the current element is not present in the input array
			flag = false // Set the flag to false and break the loop
			break
		}
	}

	// Check the result
	l := 0
	for cnt[l] == 0 {
		l++ // Find the last element that was present in the input array
	}
	for i := l + 1; i < m; i++ {
		flag = flag && b[i] < b[i+1] // Check if the output array is sorted in ascending order after the last present element
	}

	// Print the result
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
