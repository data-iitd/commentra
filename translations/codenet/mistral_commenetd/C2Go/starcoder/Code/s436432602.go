
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to run the logic of the program
func run() {
	// Declare variables
	var n, k int

	// Read input values of n and k from the user
	fmt.Print("Enter the number of elements in the array and the target sum: ")
	fmt.Scanf("%d%d", &n, &k)

	// Declare an array of size n to store the elements of the array
	a := make([]int, n)

	// Read the elements of the array from the user
	fmt.Print("Enter ", n, " integers: ")
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	// Declare a dynamic array of size k+1 to store the dp values
	dp := make([]int, k+1)

	// Initialize all dp values as false initially
	for i := 0; i <= k; i++ {
		dp[i] = 0
	}

	// Calculate the dp values for all sums from 1 to k
	for i := 1; i <= k; i++ {
		win := 0

		// Check if there exists a subset of sum i in the given array a[]
		for j := 0; j < n && a[j] <= i; j++ {
			// If a[j] can be included in the subset, then check for the next element
			if dp[i-a[j]] == 1 {
				win = 1
				break
			}
		}

		// Update the dp value for the current sum i
		dp[i] = win
	}

	// Print the result based on the dp value for the target sum k
	fmt.Print("The target sum ", k, " is ")
	if dp[k] == 1 {
		fmt.Print("First\n") // Target sum is a subset of given array
	} else {
		fmt.Print("Second\n") // Target sum is not a subset of given array
	}
}

// Main function to call the run function
func main() {
	// Call the run function to execute the logic
	run()
}

