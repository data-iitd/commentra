package main

import (
	"fmt"
)

func main() {
	// Declare variable N to hold the number of elements
	var N int
	// Read the number of elements from user input
	fmt.Scan(&N)

	// Declare variables for iteration, sum, weighted sum, and arrays
	var sum int64 = 0 // To store the total sum of elements
	var wa int64 = 0  // To store the weighted sum (1 + 2 + ... + N)
	A := make([]int, N) // Slice to hold the input elements
	sa := make([]int, N) // Slice to hold the adjusted differences
	var ans int         // Variable to store the final answer (0 or 1)
	var shou int       // Variable to store the average value

	// Read the elements into array A and calculate the total sum and weighted sum
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read each element into the array A
		sum += int64(A[i]) // Accumulate the sum of elements
		wa += int64(i + 1) // Accumulate the weighted sum
	}

	// Check if the total sum is divisible by the weighted sum
	if sum%wa != 0 {
		ans = 0 // If not divisible, set answer to 0 (NO)
	} else {
		// Calculate the average value (shou)
		shou = int(sum / wa)

		// Calculate the adjusted differences and store them in array sa
		for i := 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - shou // Adjusted difference for circular array
		}

		// Check the conditions for the adjusted differences
		for i := 0; i < N-1; i++ {
			// If the adjusted difference is non-positive and divisible by N
			if sa[i] <= 0 && sa[i]%N == 0 {
				ans = 1 // Set answer to 1 (YES)
			} else {
				ans = 0 // If any condition fails, set answer to 0 (NO)
				break   // Exit the loop early
			}
		}
	}

	// Output the final result based on the answer
	if ans == 1 {
		fmt.Println("YES") // Print YES if conditions are met
	} else {
		fmt.Println("NO")  // Print NO if conditions are not met
	}
}

// <END-OF-CODE>
