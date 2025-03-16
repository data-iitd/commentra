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

	// Read input variables
	var N, X int
	var A []int
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		A = append(A, num)
	}

	// Create a new list S by applying the accumulate function to the list A
	S := make([]int, len(A))
	S[0] = A[0]
	for i := 1; i < len(A); i++ {
		S[i] = S[i-1] + A[i]
	}

	// Initialize a variable ans with a large value
	ans := int(1e18)

	// Iterate through each element s in the list S
	for k := 1; k <= len(A); k++ {
		s := S[k-1]
		// Calculate the energy consumption E for the current index k
		E := k * X + 2 * sum(S, N-2*k-1, -k)

		// Update the minimum energy consumption ans if the current energy consumption E is smaller
		if E < ans {
			ans = E
		}
	}

	// Print the result
	fmt.Println(ans + N*X + 5*S[len(S)-1])
}

// Helper function to calculate the sum of elements in a slice
func sum(S []int, start, step int) int {
	sum := 0
	for i := start; i >= 0; i += step {
		sum += S[i]
	}
	return sum
}
