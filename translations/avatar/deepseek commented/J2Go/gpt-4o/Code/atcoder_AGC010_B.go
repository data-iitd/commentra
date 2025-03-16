package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements N from the user
	A := make([]int, N) // Create a slice A to store the elements
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read N integers from the user and store them in the slice A
	}
	if possible(N, A) { // Call the possible function to check if the slice A can be rearranged to satisfy a certain condition
		fmt.Println("YES") // Print "YES" if the condition is satisfied
	} else {
		fmt.Println("NO") // Print "NO" if the condition is not satisfied
	}
}

func possible(N int, A []int) bool {
	var sum int64 = 0 // Initialize sum to store the sum of the elements in the slice A
	for i := 0; i < N; i++ {
		sum += int64(A[i]) // Calculate the sum of the elements in the slice A
	}
	NS := int64(N * (N + 1) / 2) // Calculate the sum of the first N natural numbers (NS)
	if sum%NS != 0 {
		return false // Check if the sum of the slice A is divisible by NS. If not, return false
	}
	K := sum / NS // Calculate the value of K
	for i := 0; i < N; i++ {
		j := i
		if i == 0 {
			j = N - 1 // Calculate the index of the previous element in the slice A
		} else {
			j = i - 1
		}
		d := K - (int64(A[i]) - int64(A[j])) // Calculate the difference
		if d < 0 || d%int64(N) != 0 {
			return false // Check if the difference is negative or not divisible by N. If so, return false
		}
	}
	return true // If all elements satisfy the condition, return true
}

// <END-OF-CODE>
