
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the array and the difference d from the input
	n, d := readInput()

	// Create an integer array of size n to store the numbers
	nums := make([]int, n)

	// Read the numbers in the array from the input
	for i := 0; i < n; i++ {
		nums[i] = readInt()
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
			result += a / d + 1
			nums[i] += (a/d + 1) * d
		}
	}

	// Print the result to the console
	fmt.Println(result)
}

func readInput() (int, int) {
	// Read the input from the console
	input := strings.Split(readLine(), " ")

	// Convert the input to integers
	n, _ := strconv.Atoi(input[0])
	d, _ := strconv.Atoi(input[1])

	return n, d
}

func readLine() string {
	// Read the input from the console
	var line string
	fmt.Scanln(&line)

	return line
}

func readInt() int {
	// Read the input from the console
	var num int
	fmt.Scanln(&num)

	return num
}

