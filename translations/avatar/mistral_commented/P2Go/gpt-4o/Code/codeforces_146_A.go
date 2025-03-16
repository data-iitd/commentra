package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Ask user for the number of elements in the list
	var n int
	fmt.Scan(&n)

	// Get the list of numbers from user input
	var input string
	fmt.Scan(&input)
	numberStr := strings.Split(input, " ")
	number := make([]int, n)

	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(numberStr[i])
		number[i] = num
	}

	// Initialize variables h1 and h2 to 0
	h1 := 0
	h2 := 0
	x := 0

	// Iterate through the list of numbers
	for i := 0; i < n; i++ {
		// Check if the current number is not 4 and not 7
		if number[i] != 4 && number[i] != 7 {
			// Print "NO" and break the loop if the condition is met
			fmt.Println("NO")
			x++
			break
		}

		// If the index is less than half the length of the list, add the number to h1
		if i < n/2 {
			h1 += number[i]
		} else {
			// If the index is greater than or equal to half the length of the list, add the number to h2
			h2 += number[i]
		}
	}

	// Check if the loop was broken due to a non-4 and non-7 number
	if x == 0 {
		// If h1 and h2 are equal, print "YES"
		if h1 == h2 {
			fmt.Println("YES")
		} else {
			// If h1 and h2 are not equal, print "NO"
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
