package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Initialize a new scanner to read from standard input
var sc = bufio.NewScanner(os.Stdin)

// nextInt reads the next integer from standard input
func nextInt() int {
	sc.Scan() // Scan the next line of input
	t, err := strconv.Atoi(sc.Text()) // Convert the scanned text to an integer
	if err != nil {
		panic(err) // Panic if there is an error in conversion
	}
	return t // Return the integer value
}

// scanNums reads a specified number of integers from standard input and returns them as a slice
func scanNums(len int) (nums []int) {
	var num int
	for i := 0; i < len; i++ {
		fmt.Scan(&num) // Read an integer from standard input
		nums = append(nums, num) // Append the integer to the slice
	}
	return // Return the slice of integers
}

// pattern1 calculates a specific pattern based on the first five integers in the slice
func pattern1(l []int) int {
	n := (l[0]*l[3]) + (l[1]*l[4]) // Calculate the result based on the formula
	return n // Return the calculated value
}

// pattern2 calculates another pattern based on the maximum of the last two integers
func pattern2(l []int) int {
	n := 2 * l[2] * max(l[3], l[4]) // Calculate the result using the maximum value
	return n // Return the calculated value
}

// pattern3 calculates a third pattern that combines the minimum value and a function call
func pattern3(l []int) int {
	n := 2*l[2]*min(l[3], l[4]) + (doch(l)) // Calculate the result using the minimum value and doch function
	return n // Return the calculated value
}

// min returns the minimum value from a variable number of integer arguments
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("function min() requires at least one argument.") // Panic if no arguments are provided
	}
	res := nums[0] // Initialize the result with the first argument
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i]))) // Update the result to the minimum value
	}
	return res // Return the minimum value
}

// max returns the maximum value from a variable number of integer arguments
func max(nums ...int) int {
	if len(nums) == 0 {
		panic("function max() requires at least one argument.") // Panic if no arguments are provided
	}
	res := nums[0] // Initialize the result with the first argument
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i]))) // Update the result to the maximum value
	}
	return res // Return the maximum value
}

// doch calculates a value based on the difference between the last two integers in the slice
func doch(l []int) int {
	if l[3] > l[4] {
		return l[0] * (l[3] - l[4]) // Return the product if the fourth integer is greater
	} else {
		return l[1] * (l[4] - l[3]) // Return the product if the fifth integer is greater
	}
}

// main function where the program execution begins
func main() {
	len := 5 // Define the number of integers to read
	l := scanNums(len) // Read the integers into a slice
	// Print the minimum value from the three calculated patterns
	fmt.Println(min(pattern1(l), pattern2(l), pattern3(l)))
}
