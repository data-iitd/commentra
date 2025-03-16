
package main

import (
	"fmt"
)

func main() {
	// Read the number of elements in the array 'a'
	var n int
	fmt.Scan(&n)

	// Initialize a slice 'a' of size 'n'
	a := make([]int, n)

	// Initialize a slice 'acc' of size 'n+1' with zero as initial value
	acc := make([]int, n+1)

	// Read the elements of the array 'a' and calculate the cumulative sum
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])

		// Update the cumulative sum 'acc' for the current index 'i+1'
		acc[i+1] = acc[i] + a[i]

		// Perform modulo operation to keep the value within the range of 'MOD'
		acc[i+1] %= MOD
	}

	// Initialize the answer 'ans' to zero
	ans := 0

	// Calculate the answer using the formula
	for i := 0; i < n; i++ {
		// Calculate the contribution of the current element 'a[i]' to the answer
		temp := a[i] % MOD * (MOD + acc[n] - acc[i+1]) % MOD

		// Add the contribution to the answer
		ans += temp

		// Perform modulo operation to keep the value within the range of 'MOD'
		ans %= MOD
	}

	// Print the answer
	fmt.Println(ans)

	// Terminate the program
	return
}

