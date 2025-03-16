package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	var N, X int
	fmt.Fscanf(os.Stdin, "%d %d", &N, &X)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(os.Stdin, "%d", &A[i])
	}

	// Calculate the cumulative sum of the list A
	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	// Initialize the answer to a very large number (infinity)
	ans := math.Inf(1)

	// Iterate through the cumulative sums with an index starting from 1
	for k := 1; k <= N; k++ {
		E := float64(k*X)
		for j := N - 2*k - 1; j >= 0; j -= k {
			E += 2 * float64(S[j])
		}

		// Update the answer with the minimum value found so far
		if E < ans {
			ans = E
		}
	}

	// Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
	fmt.Println(int(ans + float64(N*X) + 5*float64(S[N-1])))
}

// <END-OF-CODE>
