package main

import "fmt"

func main() {
	// Read input numbers and operations
	var nums []int
	var operations []string
	fmt.Scanf("%v %v", &nums, &operations)

	// Initialize the answer list with a large number
	var ans int = 10000000000000000000000000

	// Call the function with initial parameters
	rememberTheNumber(nums, operations, 0, ans)

	// Print the smallest number found
	fmt.Println(ans)
}

// rememberTheNumber is a recursive function that finds the smallest number
func rememberTheNumber(nums []int, operations []string, i int, ans int) {
	// If the index i is greater than or equal to 3, return to limit recursion depth
	if i >= 3 {
		return
	}

	// Iterate over pairs of numbers to perform operations
	for j := 0; j < 4; j++ {
		for k := j + 1; k < 4; k++ {
			if nums[j]!= -1 && nums[k]!= -1 {
				s := nums[j]
				nums[j] = -1 // Mark the number as used
				t := nums[k]

				// Perform the operation based on the current operation symbol
				if operations[i] == "+" {
					nums[k] = s + t
				} else if operations[i] == "*" {
					nums[k] = s * t

				// If it's the last operation and the result is smaller than the current minimum, update ans
				if i == 2 && nums[k] < ans {
					ans = nums[k]

				// Recursively call the function with updated parameters
				rememberTheNumber(nums, operations, i+1, ans)

				// Restore the original numbers to try other combinations
				nums[j] = s
				nums[k] = t
			}
		}
	}
}

