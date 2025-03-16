package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	line, _ := reader.ReadString('\n')
	// Split the first line of input by spaces
	line = strings.Split(line, " ")
	// Convert the first line of input from string to int
	N, X := strconv.Atoi(line[0]), strconv.Atoi(line[1])
	// Initialize a variable A as an array of int
	A := make([]int, N)
	// Initialize a variable S as an array of int
	S := make([]int, N)
	// Initialize a variable ans with a large value
	ans := int(1e9)
	// Iterate through each element a in the array A
	for i := 0; i < N; i++ {
		// Read the next line of input
		line, _ := reader.ReadString('\n')
		// Convert the next line of input from string to int
		A[i], _ = strconv.Atoi(line)
	}
	// Iterate through each element a in the array A
	for i := 0; i < N; i++ {
		// Calculate the energy consumption E for the current index i
		E := i * X + 2 * sum(S[j] for j in range(N - 2*i - 1, -1, -i))
		// Update the minimum energy consumption ans if the current energy consumption E is smaller
		ans = min(ans, E)
	}
	// Print the result
	fmt.Println(ans + N * X + 5 * S[-1])
}

func sum(s []int) int {
	var sum int
	for _, v := range s {
		sum += v
	}
	return sum
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

