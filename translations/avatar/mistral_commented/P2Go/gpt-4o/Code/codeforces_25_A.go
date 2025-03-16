package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read user input and assign it to the variable 'n'
	var n int
	fmt.Scan(&n)

	// Create a slice 'list' with the same length as 'n'
	list := make([]int, n)

	// Read the input values and populate the list with the remainder of each value divided by 2
	var input string
	fmt.Scan(&input)
	values := strings.Split(input, " ")
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(values[i])
		list[i] = num % 2
	}

	// Check if the sum of all elements in the list is equal to 1
	sum := 0
	for _, value := range list {
		sum += value
	}

	if sum == 1 {
		// If the condition is true, print the index of the first occurrence of the number 1 in the list
		for i, value := range list {
			if value == 1 {
				fmt.Println("The first number with remainder 1 is:", i+1)
				break
			}
		}
	} else {
		// If the condition is false, print the index of the first occurrence of the number 0 in the list
		for i, value := range list {
			if value == 0 {
				fmt.Println("The first number with remainder 0 is:", i+1)
				break
			}
		}
	}
}

// <END-OF-CODE>
