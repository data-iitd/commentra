package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	n, _ := strconv.Atoi(readLine(reader))

	// Read the list of integers and convert them to a list of integers
	a := readInts(reader)

	// Initialize the previous value to infinity
	pre := int(^uint(0) >> 1)

	// Initialize the answer variable to accumulate the result
	ans := 0

	// Sort the list in descending order
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})

	// Iterate through the sorted list
	for j := 0; j < n; j++ {
		// Calculate the current contribution to the answer
		// It takes the minimum of (pre - 1) and the current element a[j], ensuring it's non-negative
		ans += max(0, min(pre-1, a[j]))
		
		// Update the previous value for the next iteration
		pre = max(0, min(pre-1, a[j]))
	}

	// Print the final accumulated answer
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

func readInts(reader *bufio.Reader) []int {
	line := readLine(reader)
	parts := strings.Split(line, " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
