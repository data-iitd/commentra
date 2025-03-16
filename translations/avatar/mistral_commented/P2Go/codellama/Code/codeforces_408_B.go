#######
# Import necessary libraries
#######

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define helper functions
func hpop(heap []int) int {
	return heap[0]
}
func hpush(heap []int, item int) {
	heap = append(heap, item)
	return
}

#######
# Function to find the solution
#######

func solution() {
	// Read the first line and count the number of occurrences of each color
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	boughtCount := make(map[string]int)
	for _, color := range strings.Split(line, "") {
		boughtCount[color]++
	}

	// Read the second line and count the number of occurrences of each color
	scanner.Scan()
	line = scanner.Text()
	madeCount := make(map[string]int)
	for _, color := range strings.Split(line, "") {
		madeCount[color]++
	}

	// Initialize result to 0
	res := 0

	// Iterate through each color in madeCount
	for color, count := range madeCount {
		// Check if the color is present in boughtCount
		if _, ok := boughtCount[color]; !ok {
			// If not, print -1 and exit the function
			fmt.Println(-1)
			return
		}

		// Update the result by adding the minimum of bought and made counts
		res += min(boughtCount[color], count)
	}

	// Print the result
	fmt.Println(res)
}

// Define min function
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

#######
# Main function to run the solution function for multiple test cases
#######

func main() {
	// Read the number of test cases
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	// Run the solution function for each test case
	for i := 0; i < t; i++ {
		solution()
	}
}

