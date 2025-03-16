
package main

import (
	"fmt"
	"math/big" // Import big package for handling large integers
)

const d = big.NewInt(1000000007) // Define a constant 'd' as a big.Int

func main() {
	// Initialize variables
	var n, p int

	fmt.Scan(&n) // Read the first integer 'n' from the standard input
	fmt.Scan(&p) // Read the second integer 'p' from the standard input

	mdans := make(map[int64]int64) // Initialize an empty map 'mdans' for storing distinct numbers

	// Read 'p' distinct numbers from the standard input and store them in the map 'mdans'
	for index := 0; index < p; index++ {
		var n1 int64
		fmt.Scan(&n1)
		mdans[n1] = n1 // Store the number 'n1' in the map 'mdans' with its own key
	}

	dp := make([]int64, n+1, n+1) // Initialize an array 'dp' of size 'n+1' with a default value of '0'
	dp[0] = 1                    // Initialize the first element of the array 'dp' with a value of '1'
	dp[1] = 1                    // Initialize the second element of the array 'dp' with a value of '1'

	// Initialize the third element of the array 'dp' with a value of '0' if the number '1' is present in the map 'mdans'
	if _, ok := mdans[int64(1)]; ok {
		dp[1] = 0
	}

	// Calculate the remaining elements of the array 'dp' using the previous elements
	for i := 2; i <= n; i++ {
		if _, ok := mdans[int64(i)]; ok {
			continue // Skip the current iteration if the number 'i' is present in the map 'mdans'
		}
		dp[i] = (dp[i-1] + dp[i-2]) % d // Calculate the current element of the array 'dp' as the sum of the previous two elements modulo 'd'
	}

	// Print the final result
	fmt.Printf("%v\n", dp[n]) // Print the value of the last element of the array 'dp'
}

