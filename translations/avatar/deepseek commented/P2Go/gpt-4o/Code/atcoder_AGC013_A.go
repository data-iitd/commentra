package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Reading number of elements
	var N int
	fmt.Fscan(reader, &N)
	
	// Reading list of elements
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	// Removing consecutive duplicates from list A
	var uniqueA []int
	for i := 0; i < N; i++ {
		if i == 0 || A[i] != A[i-1] {
			uniqueA = append(uniqueA, A[i])
		}
	}
	N = len(uniqueA)

	// Initializing variables for main logic
	i := 1
	ans := 0

	// Main logic to find peaks
	for i < N-1 {
		if (uniqueA[i-1] < uniqueA[i] && uniqueA[i] > uniqueA[i+1]) || (uniqueA[i-1] > uniqueA[i] && uniqueA[i] < uniqueA[i+1]) {
			ans++
			i++ // Skip next element as it's already checked
		}
		i++
	}

	// Output the total number of peaks found
	fmt.Println(ans + 1)
}

// <END-OF-CODE>
