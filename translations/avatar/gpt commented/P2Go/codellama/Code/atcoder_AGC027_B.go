package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Read input values: N (number of elements), X (a constant), and A (the list of integers)
	N, X, A := readInput()

	// Calculate the cumulative sum of the list A
	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	// Initialize the answer to a very large number (infinity)
	ans := math.MaxInt64

	// Iterate through the cumulative sums with an index starting from 1
	for k := 1; k <= N; k++ {
		// Calculate the expression E based on the current index k and the cumulative sums
		E := k*X + 2*sum(S, N-2*k-1, -1, -k)

		// Update the answer with the minimum value found so far
		if E < ans {
			ans = E
		}
	}

	// Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
	fmt.Println(ans + N*X + 5*S[N-1])
}

func readInput() (N, X int, A []int) {
	// Read input values: N (number of elements), X (a constant), and A (the list of integers)
	fmt.Scan(&N, &X)
	A = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	return
}

func sum(S []int, start, end, step int) int {
	// Calculate the sum of the list S from start to end with a step size of step
	sum := 0
	for i := start; i != end; i += step {
		sum += S[i]
	}
	return sum
}

