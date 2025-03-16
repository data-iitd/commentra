// Import necessary libraries
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Read input number of rows and columns
func readInput() (int, int) {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	inputSlice := strings.Split(input, " ")
	N, _ := strconv.Atoi(inputSlice[0])
	M, _ := strconv.Atoi(inputSlice[1])
	return N, M
}

// Initialize numpy array 'A' with given dimensions and data type
func initializeArray(N int) []int {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	inputSlice := strings.Split(input, " ")
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(inputSlice[i])
	}
	return A
}

// Calculate cumulative remainders by performing modulo M operation on the sum of previous remainders and current element
func calculateCumulativeRemainders(A []int, M int) []int {
	cum_remainders := make([]int, len(A))
	cum_remainders[0] = A[0] % M
	for i := 1; i < len(A); i++ {
		cum_remainders[i] = (cum_remainders[i-1] + A[i]) % M
	}
	return cum_remainders
}

// Count the occurrences of each cumulative remainder
func countRemainders(cum_remainders []int) map[int]int {
	remainder_counts := make(map[int]int)
	for _, remainder := range cum_remainders {
		remainder_counts[remainder]++
	}
	return remainder_counts
}

// Calculate the number of combinations of elements having the same remainder
func calculateCombinations(remainder_counts map[int]int) int {
	combinations := 0
	for _, count := range remainder_counts {
		combinations += count * (count - 1) / 2
	}
	return combinations
}

// Print the result
func printResult(combinations int) {
	fmt.Println(combinations)
}

// Main function
func main() {
	N, M := readInput()
	A := initializeArray(N)
	cum_remainders := calculateCumulativeRemainders(A, M)
	remainder_counts := countRemainders(cum_remainders)
	combinations := calculateCombinations(remainder_counts)
	printResult(combinations)
}

// 