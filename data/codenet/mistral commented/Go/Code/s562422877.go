
package main

import (
	"fmt"
	"sort"
)

func main() {
	// Initialize variables and read input
	// Code for A - Initialize variables and read input
	var N int
	fmt.Println("Enter the number of elements in the array:")
	fmt.Scanf("%d", &N)

	A := make([]int, N)
	fmt.Println("Enter the elements of the array:")
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}

	// Sort the array in ascending order
	// Code for C - Sort the array
	sort.Sort(sort.IntSlice(A))

	// Calculate the answer
	// Code for D - Calculate the answer
	var ans int
	fmt.Println("Calculating the answer...")
	for i := 1; i < N; i++ {
		ans += A[i] - A[i-1]
	}

	// Print the answer
	// Code for E - Print the answer
	fmt.Println("The answer is:", ans)
}

