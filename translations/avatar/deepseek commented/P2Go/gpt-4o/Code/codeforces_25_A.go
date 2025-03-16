package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input representing the number of elements

	var input string
	fmt.Scan(&input) // Read the input string

	// Split the input string, convert to integers, and calculate remainders modulo 2
	nums := strings.Split(input, " ")
	list := make([]int, n)
	for i, num := range nums {
		val, _ := strconv.Atoi(num)
		list[i] = val % 2
	}

	// Check if the sum of the list is 1
	sum := 0
	for _, value := range list {
		sum += value
	}

	if sum == 1 {
		for i, value := range list {
			if value == 1 {
				fmt.Println(i + 1) // Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
				break
			}
		}
	} else {
		for i, value := range list {
			if value == 0 {
				fmt.Println(i + 1) // Print the index of the first occurrence of 0 (adjusted for 1-based indexing)
				break
			}
		}
	}
}

// <END-OF-CODE>
