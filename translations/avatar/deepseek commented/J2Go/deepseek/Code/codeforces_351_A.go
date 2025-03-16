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
	var n int
	var err error

	// Step 1: Reading Input
	fmt.Fscanln(reader, &n) // Read the integer n
	input, _ := reader.ReadString('\n') // Read the second line of input
	input = strings.TrimSpace(input)
	st := strings.Split(input, " ") // Split the input into tokens

	// Step 2: Processing Input
	var arr [2 * n]float64 // Array to store the floating-point numbers
	nonInt := 0            // Counter for non-integer values
	sumBefore := 0.0       // Variables to store the sum of all numbers and the sum of their integer parts
	sum := 0.0

	for i := 0; i < 2*n; i++ {
		num, err := strconv.ParseFloat(st[i], 64) // Convert each token to a float64
		if err != nil {
			fmt.Println("Error parsing float:", err)
			return
		}
		sumBefore += num // Add to the sum of all numbers
		if num != math.Floor(num) {
			nonInt++ // Increment counter if the number is not an integer
		}
		sum += math.Floor(num) // Add the integer part of the number to the sum of integer parts
		arr[i] = num           // Store the number in the array
	}

	// Step 3: Calculating Results
	maxSum := math.Min(float64(n), float64(nonInt)) + sum
	minSum := math.Max(0, float64(nonInt-n)) + sum
	var ans float64

	if minSum > sumBefore {
		ans = minSum - sumBefore // If the minimum sum is greater than the actual sum
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum // If the maximum sum is less than the actual sum
	} else {
		x := sumBefore - math.Floor(sumBefore) // Calculate the fractional part of the sum
		ans = math.Min(1-x, x)                 // Find the smallest difference to 0 or 1
	}

	// Step 4: Output
	fmt.Printf("%.3f\n", ans) // Print the result with a precision of three decimal places
}
