
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array and the difference d from the input
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	n, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	d, _ := strconv.Atoi(line)

	// Create an integer array of size n to store the numbers
	nums := make([]int, n)

	// Read the numbers in the array from the input
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		nums[i], _ = strconv.Atoi(line)
	}

	// Initialize variables for calculating the result and the difference between two consecutive numbers
	result := 0
	a := 0

	// Iterate through the array starting from the second element
	for i := 1; i < n; i++ {
		// Calculate the difference between the current and previous numbers
		a = nums[i-1] - nums[i]

		// If the difference is positive, add the number of jumps to the result and update the current number in the array
		if a >= 0 {
			result += a/d + 1
			nums[i] += (a/d + 1) * d
		}
	}

	// Print the result to the console
	fmt.Println(result)
}

