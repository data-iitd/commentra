
package main

import (
	"fmt"
	"sort"
)

func main() {
	// Initialize input variables
	var X, Y, Z, K int // Number of elements in vectors A, B, C and the limit for output
	fmt.Scan(&X, &Y, &Z, &K) // Read input values for X, Y, Z, and K from standard input

	// Initialize vectors A, B, and C
	A := make([]int, X) // A vector of size X, initialized with zeroes
	B := make([]int, Y) // B vector of size Y, initialized with zeroes
	C := make([]int, Z) // C vector of size Z, initialized with zeroes

	// Read input values for vectors A, B, and C from standard input
	for i := 0; i < X; i++ {
		fmt.Scan(&A[i]) // Read each element of vector A
	}
	for i := 0; i < Y; i++ {
		fmt.Scan(&B[i]) // Read each element of vector B
	}
	for i := 0; i < Z; i++ {
		fmt.Scan(&C[i]) // Read each element of vector C
	}

	// Sort vectors A, B, and C in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(A)))
	sort.Sort(sort.Reverse(sort.IntSlice(B)))
	sort.Sort(sort.Reverse(sort.IntSlice(C)))

	// Create a new vector AB by adding each element of A to each element of B
	AB := make([]int, 0)
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j]) // Add A[i] and B[j] and push the sum into vector AB
		}
	}

	// Sort vector AB in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(AB)))

	// Create a new vector ABC by adding each element of AB to each element of C
	ABC := make([]int, 0)
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j]) // Add AB[i] and C[j] and push the sum into vector ABC
		}
	}

	// Sort vector ABC in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(ABC)))

	// Print K smallest elements of vector ABC
	for i := 0; i < K; i++ {
		fmt.Println(ABC[i]) // Print each element of vector ABC
	}

	// Main function ends here
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

