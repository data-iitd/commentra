package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem based on the given parameters
func solve(N int, T []int, M int, P []int, X []int) {
	// Iterate over each modification request
	for i := 0; i < M; i++ {
		ans := 0 // Initialize the answer for the current modification
		// Calculate the total time considering the current modification
		for j := 0; j < N; j++ {
			// If the current index matches the modified position, add the new time value
			if j == P[i]-1 {
				ans += X[i]
			}
			// Otherwise, add the original time value
			else {
				ans += T[j]
			}
		}
		// Output the result for the current modification
		fmt.Println(ans)
	}
}

func main() {
	// Untie cin from cout for faster input
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of time values
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	T := make([]int, N) // Vector to store the original time values
	// Read the original time values into the vector
	for i := 0; i < N; i++ {
		T[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Read the number of modifications
	M, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	P := make([]int, M) // Vector to store the positions of modifications
	X := make([]int, M) // Vector to store the new time values for modifications
	// Read the modification positions and new time values
	for i := 0; i < M; i++ {
		P[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		X[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Call the solve function to process the modifications and output results
	solve(N, T, M, P, X)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

