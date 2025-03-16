
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize scanner for user input
	sc := bufio.NewScanner(os.Stdin)
	
	// Create an array to store the sizes of three lists
	x := make([]int, 3)
	max := 0 // Variable to track the maximum size
	
	// Read the sizes of the three lists from user input
	for i := 0; i < 3; i++ {
		sc.Scan()
		x[i], _ = fmt.Sscanf(sc.Text(), "%d")
		max = int(math.Max(float64(max), float64(x[i]))) // Update max if current size is greater
	}
	
	// Read the maximum product limit
	sc.Scan()
	k, _ := fmt.Sscanf(sc.Text(), "%d")
	
	// Initialize an array of lists to store the elements for each of the three lists
	a := make([][]int64, 3)
	for i := 0; i < 3; i++ {
		a[i] = make([]int64, x[i])
	}
	
	// Read the elements for each list and sort them
	for i := 0; i < 3; i++ {
		for j := 0; j < x[i]; j++ {
			sc.Scan()
			a[i][j], _ = fmt.Sscanf(sc.Text(), "%d") // Add elements to the respective list
		}
		sort.Slice(a[i], func(i, j int) bool { return a[i][j] < a[i][j] }) // Sort the list after all elements are added
	}
	
	// Close the scanner as we no longer need input
	sc.Close()
	
	// List to store the valid sums
	ans := make([]int64, 0)
	
	// Generate all combinations of elements from the three lists
	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				// Check if the product of the indices is within the limit k
				if (i + 1) * (j + 1) * (m + 1) <= k {
					// Calculate the sum of the selected elements from each list
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
					ans = append(ans, tmp) // Add the sum to the answer list
				}
			}
		}
	}
	
	// Sort the list of sums in ascending order
	sort.Slice(ans, func(i, j int) bool { return ans[i] < ans[j] })
	
	// Get the size of the answer list
	n := len(ans)
	
	// Print the largest k sums from the answer list
	for i := 0; i < k; i++ {
		fmt.Println(ans[n-i-1]) // Print the k largest sums
	}
}

