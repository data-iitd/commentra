package main

import (
	"fmt"
	"sort"
)

// Function to read a list of integers from input
func readInts() []int {
	var n int
	fmt.Scan(&n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	return A
}

// Main function to execute the logic
func main() {
	n := 0
	fmt.Scan(&n)
	A := readInts()
	sort.Ints(A)
	ans := 0
	for i := len(A) - 2; i >= len(A)-2*n-1; i -= 2 {
		ans += A[i]
	}
	fmt.Println(ans)
}

