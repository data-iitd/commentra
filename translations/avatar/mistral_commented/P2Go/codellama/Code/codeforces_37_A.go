package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take the number of elements in the list as input
	var n int
	fmt.Scan(&n)

	// Initialize an empty list 'l' to store the input elements
	l := make([]int, 0)

	// Read the list elements from the standard input, convert them to integers and append to the list
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		l = append(l, strconv.Atoi(s))
	}

	// Initialize variables 'high' and 'tower' with initial values
	high := 1
	tower := n

	// Iterate through the list starting from the second element
	for i := 1; i < n; i++ {
		// If the current element is same as the previous one, decrement 'tower' and increment 'high'
		if l[i] == l[i-1] {
			tower--
			high++
		} else {
			// If the current element is different, check if 'high' is greater than the current maximum and update it if true
			if high > maximum {
				maximum = high
			}
			high = 1
		}
	}

	// Check if the last 'high' value is greater than the current maximum and update it if true
	if high > maximum {
		maximum = high
	}

	// Print the final result
	fmt.Println(maximum, tower)
}

// 