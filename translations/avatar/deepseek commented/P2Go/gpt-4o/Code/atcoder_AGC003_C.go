package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read an integer N
	var N int
	fmt.Scan(&N)

	// Create a slice A where each element is the product of an integer input and N plus its index i
	A := make([]int, N)
	for i := 0; i < N; i++ {
		var input int
		fmt.Scan(&input)
		A[i] = input*N + i
	}

	// Sort the slice A
	sort.Ints(A)

	// Initialize a counter cnt to 0
	cnt := 0

	// Iterate over the elements of A
	for i := 0; i < N; i++ {
		d := (A[i] % N) % 2
		if d%2 != i%2 {
			cnt++
		}
	}

	// Print the result of cnt divided by 2
	fmt.Println(cnt / 2)
}

// <END-OF-CODE>
