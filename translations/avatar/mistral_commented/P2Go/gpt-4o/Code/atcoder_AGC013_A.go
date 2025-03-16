package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Set input parameters and initialize variables
	reader := bufio.NewReader(os.Stdin)

	var N int
	fmt.Fscan(reader, &N)
	
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	// Remove consecutive duplicates
	var uniqueA []int
	for i := 0; i < N; i++ {
		if i == 0 || A[i] != A[i-1] {
			uniqueA = append(uniqueA, A[i])
		}
	}

	N = len(uniqueA)

	i := 1
	ans := 0

	// Main logic
	for i < N-1 {
		if (uniqueA[i-1] < uniqueA[i] && uniqueA[i] > uniqueA[i+1]) || (uniqueA[i-1] > uniqueA[i] && uniqueA[i] < uniqueA[i+1]) {
			ans++
			i++
		}
		i++
	}

	fmt.Println(ans + 1)
}

// <END-OF-CODE>
