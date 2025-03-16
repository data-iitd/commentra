package main

import (
	"fmt"
)

const mod = 1e9 + 7

func main() {
	var N, K int64 // Number of elements in array A and the value of K
	fmt.Scan(&N, &K)
	A := make([]int64, N) // Array to store input elements
	for i := int64(0); i < N; i++ {
		fmt.Scan(&A[i]) // Read elements of array A from standard input
	}

	// Solution
	ans1 := int64(0) // Initialize answer for the first part
	for i := int64(0); i < N; i++ { // Iterate through all elements in array A
		for j := int64(0); j < N; j++ { // Iterate through all other elements in array A
			if i >= j {
				continue // Skip if current index is greater than or equal to the index of the inner loop
			}
			if A[i] > A[j] {
				ans1++ // Increment answer if the current element is greater than the inner element
			}
			ans1 %= mod // Update answer modulo 1e9+7 to avoid overflow
		}
	}

	count := make([]int64, 2005) // Initialize an array to store the count of each unique element in array A
	for i := int64(0); i < N; i++ { // Iterate through all elements in array A
		count[A[i]-1]++ // Increment the count of the current element in the count array
	}

	ans2 := int64(0) // Initialize answer for the second part
	remain := N // Initialize the remaining number of elements to be paired
	for i := int64(0); i < 2005; i++ { // Iterate through all unique elements in array A
		remain -= count[i] // Decrement the remaining number of elements to be paired for the current unique element
		ans2 += count[i] * remain // Calculate the contribution of the current unique element to the answer
	}

	ans := int64(0) // Initialize the final answer
	tmp := K * (K - 1) // Calculate (K*(K-1))
	tmp /= 2 // Divide by 2 to get the number of unique pairs that can be formed using K elements
	tmp %= mod // Update the temporary variable modulo 1e9+7
	tmp *= ans2 // Multiply the temporary variable with the answer for the second part
	tmp %= mod // Update the temporary variable modulo 1e9+7
	ans += ans1 * K // Add the answer for the first part multiplied by K to the final answer
	ans %= mod // Update the final answer modulo 1e9+7
	ans += tmp // Add the temporary variable to the final answer
	ans %= mod // Update the final answer modulo 1e9+7

	// Output
	fmt.Println(ans) // Print the final answer
}

// <END-OF-CODE>
