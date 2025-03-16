package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function
func main() {
	// Read the number of elements (n)
	n, _ := strconv.Atoi(readLine())

	// Tokenize the input line containing the numbers
	st := strings.Split(readLine(), " ")

	// Array to store the numbers and variables for calculations
	arr := make([]float64, 2*n)
	non_int := 0 // Counter for non-integer values
	sum_before := 0.0
	sum := 0.0

	// Loop through the input numbers
	for i := 0; i < 2*n; i++ {
		// Parse the next number from the input
		num, _ := strconv.ParseFloat(st[i], 64)

		// Accumulate the total sum of the numbers
		sum_before += num

		// Check if the number is non-integer and update the counter
		if num!= float64(int(num)) {
			non_int++
		}

		// Accumulate the sum of the integer parts of the numbers
		sum += float64(int(num))

		// Store the number in the array
		arr[i] = num
	}

	// Calculate the maximum possible sum considering non-integer values
	max_sum := float64(min(n, non_int)) + sum

	// Calculate the minimum possible sum considering non-integer values
	min_sum := float64(max(0, non_int-n)) + sum

	var ans float64

	// Determine the answer based on the calculated sums
	if min_sum > sum_before {
		ans = min_sum - sum_before
	} else if max_sum < sum_before {
		ans = sum_before - max_sum
	} else {
		// Case where the total sum is between min_sum and max_sum
		x := sum_before - float64(int(sum_before))
		ans = min(1-x, x)
	}

	// Print the final answer formatted to three decimal places
	fmt.Printf("%.3f", ans)
}

// ReadLine reads a line from stdin and returns it as a string
func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return string(str)
}

// min returns the minimum of two numbers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// max returns the maximum of two numbers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

