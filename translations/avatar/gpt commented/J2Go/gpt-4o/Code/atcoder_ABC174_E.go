package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of logs and the value of k
	n, k := readInts(reader)

	// Read the lengths of the logs into a slice
	logsLength := readIntSlice(reader, n)

	// Initialize binary search bounds
	min, max := 1, int(1e9)+1000

	// Perform binary search to find the minimum possible length
	for min < max {
		mid := (min + max) / 2

		// Check if it's possible to cut the logs with the current mid length
		if canCut(mid, logsLength, k) {
			max = mid // If possible, search in the lower half
		} else {
			min = mid + 1 // Otherwise, search in the upper half
		}
	}

	// Output the minimum length found
	fmt.Fprintln(writer, min)
}

// Helper function to determine if logs can be cut with the given mid length
func canCut(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1 // Calculate the number of cuts needed
	}
	return k >= 0 // Return true if we can make the cuts within the limit of k
}

// Function to read a slice of integers from input
func readIntSlice(reader *bufio.Reader, n int) []int {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	result := make([]int, n)
	for i := 0; i < n; i++ {
		result[i], _ = strconv.Atoi(parts[i])
	}
	return result
}

// Function to read two integers from input
func readInts(reader *bufio.Reader) (int, int) {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])
	return a, b
}
