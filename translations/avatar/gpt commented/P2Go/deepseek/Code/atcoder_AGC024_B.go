package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of elements from user input
	var N int
	fmt.Scan(&N)
	
	// Read N integers from user input and store them in a slice P
	P := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&P[i])
	}
	
	// Call the editorial function to process the input
	editorial(N, P)
}

func editorial(N int, P []int) {
	// If there is only one element, the answer is 0 (no removals needed)
	if N == 1 {
		fmt.Println(0)
		return
	}
	
	// Create an array to store the positions of elements in P
	a := make([]int, N + 1)
	
	// Fill the array 'a' with the indices of the elements in P
	for i, p := range P {
		a[p] = i
	}
	
	// Initialize temporary length and maximum length variables
	tmp := 1
	maxLen := 1
	
	// Iterate through the array to find the longest increasing subsequence
	for i := 1; i < N; i++ {
		if a[i] < a[i + 1] {
			tmp += 1  // Increase the temporary length if the sequence is increasing
			maxLen = max(maxLen, tmp)  // Update the maximum length found
		} else {
			tmp = 1  // Reset temporary length if the sequence is not increasing
		}
	}
	
	// Calculate the answer as the total elements minus the length of the longest subsequence
	ans := N - maxLen
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

