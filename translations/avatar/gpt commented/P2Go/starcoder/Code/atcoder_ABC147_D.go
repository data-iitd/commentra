package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the array
	N, _ := strconv.Atoi(readLine())

	// Read the input values and create a NumPy array of integers
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(readLine())
	}

	// Initialize the result variable to store the final answer
	result := 0

	// Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
	for b := 0; b < 60; b++ {
		// Count how many numbers have the b-th bit set (1)
		bs := 0
		for _, a := range A {
			if a&(1<<b)!= 0 {
				bs++
			}
		}

		// Calculate the contribution of the b-th bit to the result
		// bs * (N - bs) gives the number of pairs with different b-th bits
		// (1 << b) gives the value of the b-th bit
		result = (result + bs * (N-bs) * (1<<b)) % 1000000007
	}

	// Print the final result
	fmt.Println(result)
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	return strings.TrimRight(string(line), "\r\n")
}

