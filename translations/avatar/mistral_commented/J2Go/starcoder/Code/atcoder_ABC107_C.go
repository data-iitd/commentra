
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the first two integers from the standard input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	K, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Allocate an integer array of size N to store the input elements
	S := make([]int, N)

	// Read the remaining elements of the array from the standard input
	for i := 0; i < N; i++ {
		S[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Initialize variables for calculating the answer
	var temp, ans int

	// Check the special case when the size of the sliding window is 1
	if K == 1 {
		// Iterate through the array to find the minimum absolute value
		for i := 0; i < N; i++ {
			temp = S[i] // Read the current element
			ans = min(ans, abs(temp)) // Update the answer if necessary
		}

		// Print the answer
		fmt.Println(ans)
	} else if N-K!= 0 { // Check the case when the size of the sliding window is not equal to the size of the array
		// Initialize variables for calculating the minimum and maximum elements in the sliding window
		var min, max int

		// Iterate through all possible positions of the sliding window
		for i := 0; i <= N-K; i++ {
			// Find the minimum and maximum elements in the current sliding window
			min = S[i]
			max = S[i+K-1]

			// Calculate the sum of the absolute values of the minimum and maximum elements
			// and update the answer if necessary
			if min < 0 && max > 0 {
				temp = 2*(abs(min)) + max
			} else {
				temp = max(abs(min), abs(max))
			}
			ans = min(ans, temp)
		}

		// Print the answer
		fmt.Println(ans)
	} else { // Check the case when the size of the sliding window is equal to the size of the array
		// Find the minimum and maximum elements in the array
		min = S[0]
		max = S[N-1]

		// Calculate the sum of the absolute values of the minimum and maximum elements
		// and print the answer directly
		if min < 0 && max > 0 {
			fmt.Println(min(2*(abs(min)) + max, (abs(min)) + 2*max))
		} else {
			fmt.Println(max(abs(min), abs(max)))
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// 