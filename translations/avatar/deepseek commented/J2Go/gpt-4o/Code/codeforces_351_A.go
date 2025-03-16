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
	reader := bufio.NewReader(os.Stdin)

	// Step 1: Reading Input
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr)) // Read the integer n
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line) // Read the second line of input

	// Step 2: Processing Input
	arr := make([]float64, 2*n) // Slice to store the floating-point numbers
	nonInt := 0                 // Counter for non-integer values
	sumBefore := 0.0            // Variable to store the sum of all numbers
	sum := 0.0                  // Variable to store the sum of their integer parts

	for i := 0; i < 2*n; i++ {
		num, _ := strconv.ParseFloat(tokens[i], 64) // Convert each token to a float64
		sumBefore += num                              // Add to the sum of all numbers
		if num != math.Floor(num) {
			nonInt++ // Increment counter if the number is not an integer
		}
		sum += math.Floor(num) // Add the integer part of the number to the sum of integer parts
		arr[i] = num           // Store the number in the slice
	}

	// Step 3: Calculating Results
	maxSum := math.Min(float64(n), float64(nonInt)) + sum // Calculate the maximum possible sum
	minSum := math.Max(0, float64(nonInt-n)) + sum        // Calculate the minimum possible sum
	var ans float64                                          // Variable to store the result

	if minSum > sumBefore {
		ans = minSum - sumBefore // If the minimum sum is greater than the actual sum
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum // If the maximum sum is less than the actual sum
	} else {
		x := sumBefore - math.Floor(sumBefore) // Calculate the fractional part of the sum
		ans = math.Min(1-x, x)                  // Find the smallest difference to 0 or 1
	}

	// Step 4: Output
	fmt.Printf("%.3f\n", ans) // Print the result with a precision of three decimal places
}

// <END-OF-CODE>
