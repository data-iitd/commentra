package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Get user input as a list of strings, split by space character, and convert each to an integer
	var a, b int
	fmt.Scan(&a, &b)

	// Find the minimum value between 'a' and 'b'
	min_value := a
	if b < min_value {
		min_value = b
	}

	// Find the maximum value between 'a' and 'b'
	max_value := a
	if b > max_value {
		max_value = b
	}

	// Print the minimum value and the average of the difference between minimum and maximum values
	fmt.Println(min_value, (max_value-min_value)/2)
}

