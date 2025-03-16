package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the size of the array
	N, _ := strconv.Atoi(readLine())

	// Create a numpy array from the input values
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(readLine())
	}

	// Initialize the result variable to 0
	result := 0

	// Loop over each bit position from 0 to 59
	for b := 0; b < 60; b++ {
		// Count the number of set bits at the current bit position
		bs := 0
		for i := 0; i < N; i++ {
			bs += A[i] >> b & 1
		}

		// Calculate the contribution of the current bit position to the result
		result = (result + bs * (N-bs) * (1<<b)) % 1000000007
	}

	// Print the final result
	fmt.Println(result)
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	return string(line)
}

