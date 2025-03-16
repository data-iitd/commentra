package main

import (
	"fmt"
)

const MAXN = 1e5 + 10 // Define the maximum size for arrays

var (
	n, m, Q int                     // Declare variables for the size of arrays and number of queries
	a       [MAXN]int               // Declare array a to store the input elements
	b       [MAXN]int               // Declare array b for storing unique elements
	id      [MAXN]int               // Declare array id for storing positions of unique elements
	vis     [MAXN]bool              // Declare a boolean array vis to mark processed elements
	cnt     [MAXN]int               // Declare an array cnt to count elements in each position
)

func main() {
	fmt.Scan(&n, &m) // Read the size of array a and the number of positions m
	fmt.Scan(&Q)      // Read the number of queries Q

	for i := 1; i <= Q; i++ {
		fmt.Scan(&a[i]) // Read the elements of array a
	}

	k := 0
	for j := Q; j > 0; j-- { // Process the elements of array a
		if !vis[a[j]] { // If the element has not been processed
			k++
			b[k] = a[j]
			vis[a[j]] = true // Mark it as processed
		}
	}

	for j, i := m, m; i > 0; i-- { // Fill the remaining positions in b
		if !vis[i] {
			b[j] = i
			j--
		}
	}

	for i := 1; i <= m; i++ {
		id[b[i]] = i // Store the position of each element in b
	}

	flag := true // Initialize flag to true
	cnt[0] = n   // Initialize the count of elements in the first position

	for i := Q; i > 0; i-- { // Iterate through the elements of array a in reverse order
		t := id[a[i]] // Get the position of the current element in b
		if cnt[t-1] > 0 { // If there is a position available one less than the current position
			cnt[t-1]-- // Decrease the count of the previous position
			cnt[t]++   // Increase the count of the current position
			vis[t] = true // Mark the current position as processed
		} else if !vis[t] { // If the current position is not available and not yet marked as processed
			flag = false // Set flag to false
			break        // Break out of the loop
		}
	}

	l := 0 // Declare variable l to find the smallest non-zero count
	for cnt[l] == 0 {
		l++ // Find the smallest index l with a non-zero count
	}

	for i := l + 1; i < m; i++ { // Check if the elements in b are in strictly increasing order
		flag = flag && (b[i] < b[i+1])
	}

	if flag {
		fmt.Println("Yes") // Print "Yes" if the conditions are met
	} else {
		fmt.Println("No") // Print "No" otherwise
	}
}

// <END-OF-CODE>
