package main

import (
	"fmt"
	"sort"
)

func readInts() []int {
	var n int
	fmt.Scan(&n) // Read the number of integers
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i]) // Read each integer into the slice
	}
	return A
}

func main() {
	var n int
	fmt.Scan(&n) // Read integer n
	A := readInts() // Read list A
	sort.Ints(A) // Sort the list A
	ans := 0 // Initialize answer variable

	// Calculate the sum of every second element from the end
	for i := len(A) - 2; i >= len(A)-2*n && i >= 0; i -= 2 {
		ans += A[i]
	}

	fmt.Println(ans) // Print the calculated sum
}

// <END-OF-CODE>
