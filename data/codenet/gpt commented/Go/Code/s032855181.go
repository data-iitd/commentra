package main

import (
	"fmt"
)

// group function determines the group classification based on the input number n.
// It returns "B" for specific values (4, 6, 9, 11) and "A" for all other values.
func group(n int) string {
	if n == 4 || n == 6 || n == 9 || n == 11 {
		return "B"
	} else {
		return "A"
	}
}

func main() {
	// Declare variables to hold the input values for x and y
	var x, y int
	
	// Read two integers from standard input
	fmt.Scan(&x, &y)

	// Check if either x or y is equal to 2, and print "No" if true
	// This is based on the problem's specific condition
	if x == 2 || y == 2 {
		fmt.Println("No")
		return // Exit the function early if the condition is met
	}

	// Determine the group classification for both x and y
	xg := group(x)
	yg := group(y)

	// Compare the group classifications of x and y
	// Print "Yes" if they belong to the same group, otherwise print "No"
	if xg == yg {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
