package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	in := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array and the difference d from the input
	in.Scan()
	n, _ := fmt.Sscan(in.Text(), &n)
	in.Scan()
	d, _ := fmt.Sscan(in.Text(), &d)

	// Create an integer array of size n to store the numbers
	nums := make([]int, n)

	// Read the numbers in the array from the input
	for i := 0; i < n; i++ {
		in.Scan()
		nums[i], _ = fmt.Sscan(in.Text(), &nums[i])
	}

	// Initialize variables for calculating the result and the difference between two consecutive numbers
	result := 0

	// Iterate through the array starting from the second element
	for i := 1; i < n; i++ {
		// Calculate the difference between the current and previous numbers
		a := nums[i-1] - nums[i]

		// If the difference is positive, add the number of jumps to the result and update the current number in the array
		if a >= 0 {
			result += a/d + 1
			nums[i] += (a/d + 1) * d
		}
	}

	// Print the result to the console
	fmt.Println(result)
}
