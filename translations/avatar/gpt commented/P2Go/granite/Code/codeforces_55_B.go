
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func rememberTheNumber(nums []int, i int, operations []string, ans *int) {
	// Base case: If we have performed 3 operations, exit the function
	if i >= 3 {
		return
	}

	// Iterate through all pairs of numbers in the list
	for j := 0; j < 4; j++ {
		for k := j + 1; k < 4; k++ {
			// Check if both numbers are not marked as used (-1)
			if nums[j]!= -1 && nums[k]!= -1 {
				// Store the current values of nums[j] and nums[k]
				s := nums[j]
				nums[j] = -1 // Mark nums[j] as used
				t := nums[k]

				// Perform the operation based on the current operation symbol
				if operations[i] == "+" {
					nums[k] = s + t // Addition operation
				} else if operations[i] == "*" {
					nums[k] = s * t // Multiplication operation
				}

				// If we are at the last operation and the result is less than the current minimum, update it
				if i == 2 && nums[k] < *ans {
					*ans = nums[k]
				}

				// Recursively call the function for the next operation
				rememberTheNumber(nums, i+1, operations, ans)

				// Backtrack: Restore the original values of nums[j] and nums[k]
				nums[j] = s
				nums[k] = t
			}
		}
	}
}

func main() {
	// Read input numbers and operations from the user
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	nums := make([]int, 4)
	for i, num := range strings.Split(input, " ") {
		nums[i], _ = strconv.Atoi(num)
	}
	operations := strings.Split(reader.ReadLineString(), " ")

	// Initialize the answer with a very large number
	ans := 100000000000000000000000000
	ansPtr := &ans

	// Start the recursive function with the initial parameters
	rememberTheNumber(nums, 0, operations, ansPtr)

	// Print the minimum result found after all operations
	fmt.Println(ans)
}

