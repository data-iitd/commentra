package main

import (
	"fmt"
)

func main() {
	var N, K int64
	// Input the number of elements and the value of K
	fmt.Scan(&N, &K)

	A := make([]int64, N+1)
	// Input the elements into the slice A
	for i := int64(1); i <= N; i++ {
		fmt.Scan(&A[i])
	}

	cur := int64(1) // Initialize current position
	dic := make([]int64, N+1) // Dictionary to store the first occurrence of each index
	for i := range dic {
		dic[i] = -1 // Initialize dictionary with -1
	}
	flg := false // Flag to indicate if we have entered a cycle

	// Process the sequence based on the value of K
	for i := int64(1); i <= K; i++ {
		// If current index has not been seen before or we are in a cycle
		if dic[cur] < 0 || flg {
			dic[cur] = i // Record the current index
			cur = A[cur] // Move to the next index
		} else if !flg { // If we have seen this index before and are not in a cycle
			tmp := K - (dic[cur] - 1) // Calculate remaining steps
			tmp %= (i - dic[cur]) // Adjust steps based on the cycle length
			i = K - tmp // Update i to skip to the end of the cycle
			flg = true // Set the flag indicating we are in a cycle
		}
	}

	// Output the final position after K steps
	fmt.Println(cur)
}

// <END-OF-CODE>
