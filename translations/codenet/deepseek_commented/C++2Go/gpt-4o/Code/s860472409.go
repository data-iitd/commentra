package main

import (
	"fmt"
)

func main() {
	var N, ans, count int // Declare variables to store the number of elements, answer, and count
	fmt.Scan(&N)         // Read the number of elements N
	A := make([]int, N) // Declare a slice A with N elements
	for i := 0; i < N; i++ { // Loop to read N elements into the slice A
		fmt.Scan(&A[i])
	}
	
	ans = 0 // Initialize answer variable ans to 0
	count := 0 // Initialize count variable to 0
	for i := 0; i < N-1; i++ { // Loop through the slice A
		if A[i] == A[i+1] { // Check if the current element is equal to the next element
			count++ // Increment the count
			if count%2 != 0 { // Check if the count is odd
				ans++ // Increment the answer variable ans
			}
		} else {
			count = 0 // Reset the count to 0 if the current element is not equal to the next element
		}
	}
	
	fmt.Println(ans) // Print the value of ans
}
