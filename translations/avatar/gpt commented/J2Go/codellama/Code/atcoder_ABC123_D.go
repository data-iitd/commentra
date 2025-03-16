package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Initialize scanner for user input
	sc := make([]int, 3)
	
	// Create an array to store the sizes of three lists
	x := make([]int, 3)
	max := 0 // Variable to track the maximum size
	
	// Read the sizes of the three lists from user input
	for i := 0; i < 3; i++ {
		sc[i] = int(nextInt())
		max = int(math.Max(float64(max), float64(sc[i]))) // Update max if current size is greater
	}
	
	// Read the maximum product limit
	k := int(nextInt())
	
	// Initialize an array of lists to store the elements for each of the three lists
	a := make([][]int, 3)
	for i := 0; i < 3; i++ {
		a[i] = make([]int, sc[i])
	}
	
	// Read the elements for each list and sort them
	for i := 0; i < 3; i++ {
		for j := 0; j < sc[i]; j++ {
			a[i][j] = int(nextInt()) // Add elements to the respective list
		}
		sort.Ints(a[i]) // Sort the list after all elements are added
	}
	
	// Close the scanner as we no longer need input
	// sc.close()
	
	// List to store the valid sums
	ans := make([]int, 0)
	
	// Generate all combinations of elements from the three lists
	for i := 0; i < sc[0]; i++ {
		for j := 0; j < sc[1]; j++ {
			for m := 0; m < sc[2]; m++ {
				// Check if the product of the indices is within the limit k
				if (i + 1) * (j + 1) * (m + 1) <= k {
					// Calculate the sum of the selected elements from each list
					tmp := a[0][sc[0] - i - 1] + a[1][sc[1] - j - 1] + a[2][sc[2] - m - 1]
					ans = append(ans, tmp) // Add the sum to the answer list
				}
			}
		}
	}
	
	// Sort the list of sums in ascending order
	sort.Ints(ans)
	
	// Get the size of the answer list
	n := len(ans)
	
	// Print the largest k sums from the answer list
	for i := 0; i < k; i++ {
		fmt.Println(ans[n - i - 1]) // Print the k largest sums
	}
}

// Function to read an integer from user input
func nextInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

// 