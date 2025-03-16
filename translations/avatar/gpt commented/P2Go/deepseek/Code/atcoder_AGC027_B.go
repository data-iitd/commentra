package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read input values: N (number of elements), X (a constant), and A (the list of integers)
	var N, X int
	var A []int
	for scanner.Scan() {
		if N == 0 {
			N, _ = strconv.Atoi(scanner.Text())
		} else if X == 0 {
			X, _ = strconv.Atoi(scanner.Text())
		} else {
			num, _ := strconv.Atoi(scanner.Text())
			A = append(A, num)
			if len(A) == N {
				break
			}
		}
	}

	// Calculate the cumulative sum of the list A
	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	// Initialize the answer to a very large number (infinity)
	ans := 1e18

	// Iterate through the cumulative sums with an index starting from 1
	for k := 1; k <= N; k++ {
		// Calculate the expression E based on the current index k and the cumulative sums
		E := k * X + 2 * sumSublist(S, N-2*k-1, -1, k)

		// Update the answer with the minimum value found so far
		if E < ans {
			ans = E
		}
	}

	// Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
	fmt.Println(ans + int(float64(N)*float64(X)) + 5*S[N-1])
}

// Helper function to sum a sublist with a custom step
func sumSublist(list []int, start, end, step int) int {
	sum := 0
	for i := start; i != end; i += step {
		sum += list[i]
	}
	return sum
}
