package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(N int, T []int, M int, P []int, X []int) {
	// Iterate over each modification request
	for i := 0; i < M; i++ {
		ans := 0 // Initialize the answer for the current modification
		// Calculate the total time considering the current modification
		for j := 0; j < N; j++ {
			// If the current index matches the modified position, add the new time value
			if j == P[i]-1 {
				ans += X[i]
			} else {
				ans += T[j]
			}
		}
		// Output the result for the current modification
		fmt.Println(ans)
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N) // Read the number of time values
	T := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &T[i]) // Read the original time values into the vector
	}

	var M int
	fmt.Fscan(reader, &M) // Read the number of modifications
	P := make([]int, M)
	X := make([]int, M)
	for i := 0; i < M; i++ {
		fmt.Fscan(reader, &P[i], &X[i]) // Read the modification positions and new time values
	}

	// Call the solve function to process the modifications and output results
	solve(N, T, M, P, X)
}

