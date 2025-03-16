package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Type definitions for convenience
type ll int64
type PII [2]int
type PLL [2]ll

// Constants for large values and precision
const (
	INF  = 1000000000
	MOD  = 1000000007
	EPS  = 0.00000001
)

func main() {
	// Input the sizes of the three arrays and the number K
	var X, Y, Z, K ll
	fmt.Scanf("%d %d %d %d\n", &X, &Y, &Z, &K)

	// Declare vectors to hold the input values
	A := make([]ll, X)
	B := make([]ll, Y)
	C := make([]ll, Z)

	// Read values into vector A
	for i := range A {
		fmt.Scanf("%d\n", &A[i])
	}

	// Read values into vector B
	for i := range B {
		fmt.Scanf("%d\n", &B[i])
	}

	// Read values into vector C
	for i := range C {
		fmt.Scanf("%d\n", &C[i])
	}

	// Sort the vectors in descending order to facilitate maximum sum calculations
	sort.Slice(A, func(i, j int) bool { return A[i] > A[j] })
	sort.Slice(B, func(i, j int) bool { return B[i] > B[j] })
	sort.Slice(C, func(i, j int) bool { return C[i] > C[j] })

	// Create a vector to store the sums of elements from A and B
	AB := make([]ll, 0)

	// Calculate all possible sums of elements from A and B
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j])
		}
	}

	// Sort the sums in descending order
	sort.Slice(AB, func(i, j int) bool { return AB[i] > AB[j] })

	// Create a vector to store the final sums including elements from C
	ABC := make([]ll, 0)

	// Calculate sums of the top K elements from AB with each element from C
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j])
		}
	}

	// Sort the final sums in descending order
	sort.Slice(ABC, func(i, j int) bool { return ABC[i] > ABC[j] })

	// Output the top K sums from the final vector
	for i := 0; i < K; i++ {
		fmt.Printf("%d\n", ABC[i])
	}
}

