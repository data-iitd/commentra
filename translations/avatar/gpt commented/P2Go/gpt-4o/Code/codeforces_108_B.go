package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func s() string {
	// Read an input line (not used in the logic)
	var input string
	fmt.Scanln(&input)

	// Read a line of integers, split by spaces, and convert them to a slice of integers
	var a []int
	fmt.Scanln(&input)
	for _, str := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(str)
		a = append(a, num)
	}

	// Sort the slice of integers in ascending order
	sort.Ints(a)

	// Iterate through the sorted slice starting from the second element
	for i := 1; i < len(a); i++ {
		// Check if the current element is different from the previous one
		// and if it is less than double the previous element
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			// If the condition is met, return 'YES'
			return "YES"
		}
	}

	// If no such pair is found, return 'NO'
	return "NO"
}

func main() {
	// Call the function and print the result
	fmt.Println(s())
}

// <END-OF-CODE>
