package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Reading Input
	// The code reads input values for N, X, and a list of integers A.
	// This is done using bufio.NewScanner(os.Stdin).
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	X, _ := strconv.Atoi(scanner.Text())
	A := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		A[i], _ = strconv.Atoi(scanner.Text())
	}

	// Step 2: Accumulating Sums
	// The code uses the built-in function "range" to iterate over the list A.
	// The variable s is initialized to 0.
	// The variable ans is initialized to 0.
	// The code iterates over the list A with an index i starting from 0.
	// For each i, it adds A[i] to s and stores the result in s.
	// It then updates ans with the sum of s.
	s := 0
	ans := 0
	for _, a := range A {
		s += a
		ans += s
	}

	// Step 3: Initializing Answer
	// The variable ans is initialized to infinity (math.MaxInt64).
	ans = int64(math.MaxInt64)

	// Step 4: Calculating Energy
	// The code iterates over the list A with an index k starting from 1.
	// For each k, it calculates the energy E using the formula k * X + 2 * ans - 2 * sum(A[j] for j in range(N - 2 * k - 1, -1, -k)).
	// It then updates ans with the minimum value between the current ans and the calculated E.
	for k := 1; k < N; k++ {
		E := int64(k * X + 2 * ans - 2 * sum(A[j] for j in range(N - 2 * k - 1, -1, -k)))
		ans = min(ans, E)
	}

	// Step 5: Final Calculation
	// After the loop, the code calculates the final result by adding ans to N * X + 5 * A[-1] and prints it.
	fmt.Println(ans + int64(N * X + 5 * A[-1]))
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func sum(A []int) int {
	var s int
	for _, a := range A {
		s += a
	}
	return s
}

