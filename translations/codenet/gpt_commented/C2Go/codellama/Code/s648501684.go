package main

import "fmt"

func main() {
	// Declare variables to hold the number of elements (n), the threshold (k), and the number of queries (q)
	var n, k, q int64

	// Read the values of n, k, and q from user input
	fmt.Scanf("%d%d%d", &n, &k, &q)

	// Initialize an array to count occurrences of each element, with size n
	arr := make([]int, n)
	// Set all elements of the array to 0
	for i := 0; i <= n; i++ {
		arr[i] = 0 // Initialize count for each element to zero
	}

	// Process each query to count occurrences of the queried elements
	for i := 0; i < q; i++ {
		var temp int64
		// Read the queried element and increment its count in the array
		fmt.Scanf("%d", &temp)
		arr[temp] += 1 // Increment the count for the queried element
	}

	// Check each element from 1 to n to see if its count exceeds the threshold (q - k)
	for i := 1; i <= n; i++ {
		// If the count of the element is greater than (q - k), print "Yes"
		if arr[i] > (q - k) {
			fmt.Println("Yes")
		} else {
			// Otherwise, print "No"
			fmt.Println("No")
		}
	}
}

