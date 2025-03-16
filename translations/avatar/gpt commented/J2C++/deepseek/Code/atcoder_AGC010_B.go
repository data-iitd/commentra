package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the user
	var N int
	fmt.Scan(&N)
	
	// Initialize an array A to hold N integers
	A := make([]int, N)
	
	// Populate the array A with N integers from user input
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	
	// Check if it is possible to achieve the desired condition with the array A
	if possible(N, A) {
		// If possible, print "YES"
		fmt.Println("YES")
	} else {
		// If not possible, print "NO"
		fmt.Println("NO")
	}
}

// Method to determine if the condition can be satisfied
func possible(N int, A []int) bool {
	// Calculate the sum of all elements in the array A
	var sum int64 = 0
	for i := 0; i < N; i++ {
		sum += int64(A[i])
	}
	
	// Calculate the expected sum NS based on the formula for the sum of the first N natural numbers
	var NS int64 = int64(N) * int64(N + 1) / 2
	
	// Check if the total sum is divisible by NS; if not, return false
	if sum % NS != 0 {
		return false
	}
	
	// Calculate the value of K which is the target average
	K := sum / NS
	
	// Verify the condition for each element in the array
	for i := 0; i < N; i++ {
		// Determine the previous index in a circular manner
		j := i
		if i == 0 {
			j = N - 1
		}
		
		// Calculate the difference d needed to satisfy the condition
		d := K - int64(A[i] - A[j])
		
		// If d is negative or not divisible by N, return false
		if d < 0 || d % int64(N) != 0 {
			return false
		}
	}
	
	// If all conditions are satisfied, return true
	return true
}

