package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	// Read input from standard input
	var N, X int
	fmt.Fscanf(os.Stdin, "%d %d", &N, &X)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(os.Stdin, "%d", &A[i])
	}

	// Create a new slice S by applying the accumulate function to the slice A
	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	// Initialize a variable ans with a large value
	ans := math.Inf(1)

	// Iterate through each element s in the slice S
	for k := 1; k <= N/2; k++ {
		// Calculate the energy consumption E for the current index k
		E := float64(k)*float64(X) + 2*sum(S, N, k)

		// Update the minimum energy consumption ans if the current energy consumption E is smaller
		if E < ans {
			ans = E
		}
	}

	// Print the result
	fmt.Println(int(ans + float64(N)*float64(X) + 5*float64(S[N-1])))
}

// Function to calculate the sum for the energy consumption
func sum(S []int, N, k int) float64 {
	total := 0
	for j := N - 2*k - 1; j >= 0; j -= k {
		total += S[j]
	}
	return float64(total)
}
