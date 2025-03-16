package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Step 1: Read the input value N
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Step 2: Read the elements of the array A
	}
	count := 0 // Step 3: Initialize a counter 'count' to zero
	for i := 0; i < N; i++ {
		if i == N-1 {
			count++ // Step 5: Check if the current index i is the last index
		} else if A[i] == A[i+1] {
			// Step 6: If the current element is equal to the next element
		} else if A[i] < A[i+1] {
			for A[i] <= A[i+1] {
				i++
				if i == N-1 {
					break
				}
			}
			count++ // Step 7: Increment the counter 'count' after each segment
		} else {
			for A[i] >= A[i+1] {
				i++
				if i == N-1 {
					break
				}
			}
			count++ // Step 8: Increment the counter 'count' after each segment
		}
	}
	fmt.Println(count) // Step 9: Print the value of the counter 'count'
}

// <END-OF-CODE>
