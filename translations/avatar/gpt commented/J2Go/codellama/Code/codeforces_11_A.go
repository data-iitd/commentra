package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	in := bufio.NewScanner(os.Stdin)

	// Reading the number of elements (n) and the divisor (d) from user input
	n, _ := strconv.Atoi(in.Text())
	d, _ := strconv.Atoi(in.Text())

	// Initializing an array to hold the numbers
	nums := make([]int, n)

	// Reading n integers from user input and storing them in the nums array
	for i := 0; i < n; i++ {
		nums[i], _ = strconv.Atoi(in.Text())
	}

	// Initializing result variable to count the total adjustments made
	result := 0
	a := 0 // Variable to hold the difference between consecutive elements

	// Looping through the nums array starting from the second element
	for i := 1; i < n; i++ {
		// Calculating the difference between the previous and current element
		a = nums[i-1] - nums[i]

		// If the difference is non-negative, adjustments are needed
		if a >= 0 {
			// Calculating how many times we can adjust the current element
			result += a / d + 1

			// Adjusting the current element to maintain the required condition
			nums[i] += (a / d + 1) * d
		}
	}

	// Printing the total number of adjustments made
	fmt.Println(result)
}

