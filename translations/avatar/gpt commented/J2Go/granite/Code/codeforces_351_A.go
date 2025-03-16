
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements (n)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Read the numbers from the input line
	scanner.Scan()
	line := scanner.Text()
	tokens := strings.Split(line, " ")

	// Array to store the numbers and variables for calculations
	arr := make([]float64, 2*n)
	nonInt := 0 // Counter for non-integer values
	sumBefore := 0.0 // Variable to store the sum of the numbers before flooring
	sum := 0.0 // Variable to store the sum of the integer parts of the numbers

	// Loop through the input numbers
	for i := 0; i < 2*n; i++ {
		// Parse the next number from the input
		num, _ := strconv.ParseFloat(tokens[i], 64)

		// Accumulate the total sum of the numbers
		sumBefore += num

		// Check if the number is non-integer and update the counter
		if num!= math.Floor(num) {
			nonInt++
		}

		// Accumulate the sum of the integer parts of the numbers
		sum += math.Floor(num)

		// Store the number in the array
		arr[i] = num
	}

	// Calculate the maximum possible sum considering non-integer values
	maxSum := math.Min(float64(n), float64(nonInt)) + sum

	// Calculate the minimum possible sum considering non-integer values
	minSum := math.Max(0.0, float64(nonInt-n)) + sum

	var ans float64 // Variable to store the final answer

	// Determine the answer based on the calculated sums
	if minSum > sumBefore {
		ans = minSum - sumBefore // Case where minSum is greater than the total sum
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum // Case where maxSum is less than the total sum
	} else {
		// Case where the total sum is between minSum and maxSum
		x := sumBefore - math.Floor(sumBefore)
		ans = math.Min(1-x, x) // Calculate the minimum distance to the nearest integer
	}

	// Print the final answer formatted to three decimal places
	fmt.Printf("%.3f", ans)
}

