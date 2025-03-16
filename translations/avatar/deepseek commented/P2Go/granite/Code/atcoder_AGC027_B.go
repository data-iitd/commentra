
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Reading Input
	// The code reads input values for N, X, and a list of integers A.
	// This is done using bufio.NewScanner(os.Stdin).Scan() and strconv.Atoi().
	var N, X int
	var A []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	X, _ = strconv.Atoi(scanner.Text())
	A = make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		A[i], _ = strconv.Atoi(scanner.Text())
	}

	// Step 2: Accumulating Sums
	// The code uses accumulate(A) to create a list of accumulated sums of A.
	// This is stored in the variable S.
	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	// Step 3: Initializing Answer
	// The variable ans is initialized to infinity (float("inf")).
	ans := float("inf")

	// Step 4: Calculating Energy
	// The code iterates over the accumulated sums S with an index k starting from 1.
	// For each k, it calculates the energy E using the formula k * X + 2 * sum(S[j] for j in range(N - 2 * k - 1, -1, -k)).
	// It then updates ans with the minimum value between the current ans and the calculated E.
	for k := 1; k <= N; k++ {
		E := k * X + 2*sum(S, N-2*k-1, -k)
		if E < ans {
			ans = E
		}
	}

	// Step 5: Final Calculation
	// After the loop, the code calculates the final result by adding ans to N * X + 5 * S[-1] and prints it.
	fmt.Println(ans + N*X + 5*S[N-1])
}

func sum(S []int, start, step int) int {
	sum := 0
	for i := start; i >= 0; i -= step {
		sum += S[i]
	}
	return sum
}

