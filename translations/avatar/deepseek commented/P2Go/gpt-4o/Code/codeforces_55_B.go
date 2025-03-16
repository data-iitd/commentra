package main

import (
	"fmt"
	"math"
)

func rememberTheNumber(nums []int, i int, operations []string, ans *[]int) {
	// If the index i is greater than or equal to 3, return to limit recursion depth
	if i >= 3 {
		return
	}

	// Iterate over pairs of numbers to perform operations
	for j := 0; j < 4; j++ {
		for k := j + 1; k < 4; k++ {
			if nums[j] != -1 && nums[k] != -1 {
				s := nums[j]
				nums[j] = -1 // Mark the number as used
				t := nums[k]

				// Perform the operation based on the current operation symbol
				if operations[i] == "+" {
					nums[k] = s + t
				} else if operations[i] == "*" {
					nums[k] = s * t
				}

				// If it's the last operation and the result is smaller than the current minimum, update ans
				if i == 2 && nums[k] < (*ans)[0] {
					(*ans)[0] = nums[k]
				}

				// Recursively call the function with updated parameters
				rememberTheNumber(nums, i+1, operations, ans)

				// Restore the original numbers to try other combinations
				nums[j] = s
				nums[k] = t
			}
		}
	}
}

func main() {
	// Read input numbers and operations
	var nums [4]int
	for i := 0; i < 4; i++ {
		fmt.Scan(&nums[i])
	}
	var operations [3]string
	for i := 0; i < 3; i++ {
		fmt.Scan(&operations[i])
	}

	// Initialize the answer with a large number
	ans := []int{math.MaxInt64}

	// Call the function with initial parameters
	rememberTheNumber(nums[:], 0, operations[:], &ans)

	// Print the smallest number found
	fmt.Println(ans[0])
}

// <END-OF-CODE>
