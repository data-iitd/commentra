package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input for the number of elements
	var n int
	fmt.Scan(&n)

	// Read a line of input, split it into individual strings, convert them to integers, and store them in a list
	var l1 []int
	fmt.Scan(&l1)
	l1 = strings.Split(l1, " ")
	for i := 0; i < len(l1); i++ {
		l1[i], _ = strconv.Atoi(l1[i])
	}

	// Sort the list of integers in ascending order
	sort.Ints(l1)

	// Assign the maximum value in the list to variable 'a'
	a := l1[len(l1)-1]

	// Assign the minimum value in the list to variable 'b'
	b := l1[0]

	// Check if the maximum and minimum values are the same
	if a == b {
		// If they are the same, the difference is zero and the number of pairs is n choose 2
		fmt.Println(a - b, (n) * (n - 1) / 2)
	} else {
		// Count occurrences of the maximum value 'a' in the list
		ac := 0
		for i := 0; i < len(l1); i++ {
			if l1[i] == a {
				ac++
			}
		}

		// Count occurrences of the minimum value 'b' in the list
		bc := 0
		for i := 0; i < len(l1); i++ {
			if l1[i] == b {
				bc++
			}
		}

		// Calculate the difference between the maximum and minimum values, and the product of their counts
		fmt.Println(a - b, ac * bc)
	}
}

