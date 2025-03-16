package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the values of n and m from input
	n, m := _input()

	// Read a list of integers from input
	lst := _inputList()

	// Initialize a map to count occurrences of each integer in the list
	l := make(map[int]int)

	// Count the occurrences of each integer in the list
	for i := 0; i < n; i++ {
		l[lst[i]]++
	}

	// Initialize the result variable to store the final count
	res := 0

	// Calculate the result based on the occurrences of integers
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			// If the current integer appears more than once
			res += n - i - l[lst[i]] // Add the number of valid pairs
			l[lst[i]]--              // Decrease the count of this integer
		} else {
			// If the current integer appears only once
			res += n - i - 1 // Add the number of valid pairs for unique integers
		}
	}

	// Print the final result
	fmt.Println(res)
}

// _input reads a line of input, splits it into parts, and converts each part to an integer
func _input() (int, int) {
	var input string
	fmt.Scanln(&input)
	parts := strings.Fields(input)
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	return n, m
}

// _inputList reads a line of input and returns a slice of integers
func _inputList() []int {
	var input string
	fmt.Scanln(&input)
	parts := strings.Fields(input)
	list := make([]int, len(parts))
	for i, part := range parts {
		list[i], _ = strconv.Atoi(part)
	}
	return list
}

// <END-OF-CODE>
