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
	input, _ := os.ReadFile("/dev/stdin")
	parts := strings.Fields(string(input))
	N, _ := strconv.Atoi(parts[0])
	X, _ := strconv.Atoi(parts[1])
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(parts[i+2])
	}

	// Step 2: Accumulating Sums
	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	// Step 3: Initializing Answer
	ans := math.Inf(1)

	// Step 4: Calculating Energy
	for k := 1; k <= N; k++ {
		E := float64(k)*float64(X)
		for j := N - 2*k - 1; j >= 0; j -= k {
			E += 2 * float64(S[j])
		}
		if E < ans {
			ans = E
		}
	}

	// Step 5: Final Calculation
	result := ans + float64(N)*float64(X) + 5*float64(S[N-1])
	fmt.Println(result)
}

// <END-OF-CODE>
