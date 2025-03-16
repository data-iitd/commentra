package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Initialize a scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from standard input
func nextInt() int {
	sc.Scan() // Scan the next token from standard input
	t, err := strconv.Atoi(sc.Text()) // Convert the token to an integer
	if err != nil { // If there was an error, panic
		panic(err)
	}
	return t // Return the integer
}

// Function to read multiple integers from standard input
func scanNums(len int) (nums []int) {
	// Initialize an empty slice to store the numbers
	nums = make([]int, len)

	// Read each number from standard input and append it to the slice
	for i := 0; i < len; i++ {
		fmt.Scan(&nums[i]) // Read a number from standard input
	}

	// Return the slice of numbers
	return
}

// Function to calculate the first pattern
func pattern1(l []int) int {
	// Calculate the value of n using the given formula
	n := (l[0]*l[3])+(l[1]*l[4])

	// Return the value of n
	return n
}

// Function to calculate the second pattern
func pattern2(l []int) int {
	// Calculate the maximum of l[3] and l[4]
	maxNum := max(l[3], l[4])

	// Calculate the value of n using the given formula
	n := 2 * l[2] * maxNum

	// Return the value of n
	return n
}

// Function to calculate the third pattern
func pattern3(l []int) int {
	// Calculate the minimum of l[3] and l[4]
	minNum := min(l[3], l[4])

	// Calculate the value of n using the given formula
	n := 2 * l[2] * minNum + doch(l)

	// Return the value of n
	return n
}

// Function to find the minimum of a list of numbers
func min(nums ...int) int {
	// If the list is empty, panic with an error message
	if len(nums) == 0 {
		panic("function min() requires at least one argument.")
	}

	// Initialize the minimum value as the first number in the list
	res := nums[0]

	// Iterate through the list and update the minimum value if necessary
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}

	// Return the minimum value
	return res
}

// Function to find the maximum of a list of numbers
func max(nums ...int) int {
	// If the list is empty, panic with an error message
	if len(nums) == 0 {
		panic("function max() requires at least one argument.")
	}

	// Initialize the maximum value as the first number in the list
	res := nums[0]

	// Iterate through the list and update the maximum value if necessary
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}

	// Return the maximum value
	return res
}

// Helper function to calculate the difference between the larger and smaller of two numbers
func doch(l []int) int {
	// If l[3] is greater than l[4], return the product of l[0] and the difference between l[3] and l[4]
	if l[3] > l[4] {
		return l[0] * (l[3] - l[4])
	} else {
		// Otherwise, return the product of l[1] and the difference between l[4] and l[3]
		return l[1] * (l[4] - l[3])
	}
}

// Main function to read input and call the pattern functions
func main() {
	// Read the length of the input list
	len := 5

	// Read the input list from standard input
	l := scanNums(len)

	// Calculate and print the minimum of the three patterns
	fmt.Println(min(pattern1(l), pattern2(l), pattern3(l)))
}
