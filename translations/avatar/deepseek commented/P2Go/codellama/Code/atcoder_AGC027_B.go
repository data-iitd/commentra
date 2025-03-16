package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Reading Input
	// The code reads input values for N, X, and a list of integers A.
	// This is done using strings.Split(os.Args[1], " ")
	N, X, A := strings.Split(os.Args[1], " ")[0], strings.Split(os.Args[1], " ")[1], strings.Split(os.Args[1], " ")[2:]

	// Step 2: Accumulating Sums
	// The code uses accumulate(A) to create a list of accumulated sums of A.
	// This is stored in the variable S.
	S := make([]int, len(A))
	for i := 0; i < len(A); i++ {
		if i == 0 {
			S[i] = A[i]
		} else {
			S[i] = S[i-1] + A[i]
		}
	}

	// Step 3: Initializing Answer
	// The variable ans is initialized to infinity (math.MaxInt64).
	ans := math.MaxInt64

	// Step 4: Calculating Energy
	// The code iterates over the accumulated sums S with an index k starting from 1.
	// For each k, it calculates the energy E using the formula k * X + 2 * sum(S[j] for j in range(N - 2 * k - 1, -1, -k)).
	// It then updates ans with the minimum value between the current ans and the calculated E.
	for k := 1; k < len(S); k++ {
		E := k*X + 2*sum(S, N-2*k-1, -1, -k)
		if E < ans {
			ans = E
		}
	}

	// Step 5: Final Calculation
	// After the loop, the code calculates the final result by adding ans to N * X + 5 * S[-1] and prints it.
	fmt.Println(ans + N*X + 5*S[len(S)-1])
}

func sum(S []int, start, end, step int) int {
	sum := 0
	for i := start; i != end; i += step {
		sum += S[i]
	}
	return sum
}

