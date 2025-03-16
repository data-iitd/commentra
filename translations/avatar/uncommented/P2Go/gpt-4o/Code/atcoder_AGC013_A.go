package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
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

	ans := 0
	for i := 1; i < N-1; i++ {
		if (uniqueA[i-1] < uniqueA[i] && uniqueA[i] > uniqueA[i+1]) || (uniqueA[i-1] > uniqueA[i] && uniqueA[i] < uniqueA[i+1]) {
			ans++
			i++ // Skip the next element
		}
	}
	fmt.Println(ans + 1)
}

// <END-OF-CODE>
