package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Take the first line of input which are two integers 'num' and 'k'
	num, k := takeInput()

	// Comment: Initialize 'num' and 'k' with the values from user input

	// Take the second line of input which is a list 'arr' of integers
	arr := takeInputList()

	// Comment: Initialize an empty list 'arr' to store the input integers

	// Create an empty set 'different' to store unique integers
	different := make(map[int]bool)

	// Comment: Initialize an empty set 'different' to store unique integers

	// Sort the list 'arr' in ascending order
	sort.Ints(arr)

	// Comment: Sort the list 'arr' in ascending order for easier comparison

	// Iterate through each integer 'x' in the sorted list 'arr'
	for _, x := range arr {

		// Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
		if (x % k != 0 || !different[x/k]) {

			// If the condition is true, add 'x' to the set 'different'
			different[x] = true

			// Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'

		}

		// Update the maximum length of 'different' seen so far
		temp := max(len(different), temp)

		// Comment: After the loop, 'temp' stores the maximum length of 'different' seen during the iteration

	}

	// Print the maximum length of 'different'
	fmt.Println(temp)

	// Comment: Finally, print the maximum length of 'different'
}

func takeInput() (int, int) {
	var num, k int
	fmt.Scan(&num, &k)
	return num, k
}

func takeInputList() []int {
	var arr []int
	fmt.Scan(&arr)
	return arr
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Comment: 