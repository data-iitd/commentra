package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of elements
	var n int
	fmt.Scan(&n)

	// Read a line of input, split it into individual elements, and create a slice that contains 1 for odd numbers and 0 for even numbers
	var list []int
	var input string
	fmt.Scan(&input)
	for _, x := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(x)
		if num%2 == 0 {
			list = append(list, 0)
		} else {
			list = append(list, 1)
		}
	}

	// Check if there is exactly one odd number in the list
	oddCount := 0
	var oddIndex int
	for i, v := range list {
		if v == 1 {
			oddCount++
			oddIndex = i + 1 // 1-based index
		}
	}

	if oddCount == 1 {
		// If there is one odd number, print its position (1-based index)
		fmt.Println(oddIndex)
	} else {
		// If there are no odd numbers, print the position of the first even number (1-based index)
		for i, v := range list {
			if v == 0 {
				fmt.Println(i + 1) // 1-based index
				break
			}
		}
	}
}

// <END-OF-CODE>
