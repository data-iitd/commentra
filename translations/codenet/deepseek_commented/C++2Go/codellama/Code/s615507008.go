package main

import (
	"fmt"
	"io"
	"os"
	"strconv"
)

func solve(N int64, T []int64, M int64, P []int64, X []int64) {
	// Solve function: This function processes the input data to calculate and output the results for each operation.
	for i := int64(0); i < M; i++ {
		// Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
		ans := int64(0)
		for j := int64(0); j < N; j++ {
			if j == P[i]-1 {
				ans += X[i]
			} else {
				ans += T[j]
			}
		}
		fmt.Println(ans)
	}
}

func main() {
	// Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
	var N int64
	fmt.Fscan(os.Stdin, &N)
	T := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Fscan(os.Stdin, &T[i])
	}
	var M int64
	fmt.Fscan(os.Stdin, &M)
	P := make([]int64, M)
	X := make([]int64, M)
	for i := int64(0); i < M; i++ {
		fmt.Fscan(os.Stdin, &P[i], &X[i])
	}
	solve(N, T, M, P, X)
}

// 