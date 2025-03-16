package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a buffered reader to read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements (n)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	// Read the line containing the numbers
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	// Variables for calculations
	nonInt := 0 // Counter for non-integer values
	sumBefore := 0.0
	sum := 0.0

	// Loop through the input numbers
	for i := 0; i < 2*n; i++ {
		num, _ := strconv.ParseFloat(tokens[i], 64)

		// Accumulate the total sum of the numbers
		sumBefore += num

		// Check if the number is non-integer and update the counter
		if num != math.Floor(num) {
			nonInt++
		}

		// Accumulate the sum of the integer parts of the numbers
		sum += math.Floor(num)
	}

	// Calculate the maximum possible sum considering non-integer values
	maxSum := math.Min(float64(n), float64(nonInt)) + sum

	// Calculate the minimum possible sum considering non-integer values
	minSum := math.Max(0, float64(nonInt)-float64(n)) + sum

	var ans float64 // Variable to store the final answer

	// Determine the answer based on the calculated sums
	if minSum > sumBefore {
		ans = minSum - sumBefore // Case where min_sum is greater than the total sum
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum // Case where max_sum is less than the total sum
	} else {
		// Case where the total sum is between min_sum and max_sum
		x := sumBefore - math.Floor(sumBefore)
		ans = math.Min(1-x, x) // Calculate the minimum distance to the nearest integer
	}

	// Print the final answer formatted to three decimal places
	fmt.Printf("%.3f\n", ans)
}

// <END-OF-CODE>
