package main

import (
	"fmt"
	"sort"
)

func main() {
	var x [3]int
	var max int

	// Read the sizes of the three lists from user input
	for i := 0; i < 3; i++ {
		fmt.Scan(&x[i])
		if x[i] > max {
			max = x[i]
		}
	}

	// Read the maximum product limit
	var k int
	fmt.Scan(&k)

	// Initialize a slice of slices to store the elements for each of the three lists
	var a [][]int64
	for i := 0; i < 3; i++ {
		var list []int64
		for j := 0; j < x[i]; j++ {
			var value int64
			fmt.Scan(&value)
			list = append(list, value)
		}
		sort.Slice(list, func(p, q int) bool {
			return list[p] < list[q]
		})
		a = append(a, list)
	}

	// List to store the valid sums
	var ans []int64

	// Generate all combinations of elements from the three lists
	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				// Check if the product of the indices is within the limit k
				if (i+1)*(j+1)*(m+1) <= int64(k) {
					// Calculate the sum of the selected elements from each list
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
					ans = append(ans, tmp) // Add the sum to the answer list
				}
			}
		}
	}

	// Sort the list of sums in ascending order
	sort.Slice(ans, func(p, q int) bool {
		return ans[p] < ans[q]
	})

	// Get the size of the answer list
	n := len(ans)

	// Print the largest k sums from the answer list
	for i := 0; i < k; i++ {
		fmt.Println(ans[n-i-1]) // Print the k largest sums
	}
}
