package main

import (
	"fmt"
)

func group(n int) string { // Function to determine group based on input number n
	if n == 4 || n == 6 || n == 9 || n == 11 { // Check if number belongs to group B
		return "B"
	} else {
		return "A"
	}
}

func main() { // Main function
	var x, y int // Declare variables x and y of type int
	fmt.Scan(&x, &y) // Read input values of x and y from standard input

	if x == 2 || y == 2 { // Check if either x or y is equal to 2
		fmt.Println("No") // If yes, print "No" and exit
		return
	}

	xg := group(x) // Determine group of number x
	yg := group(y) // Determine group of number y

	if xg == yg { // Check if both numbers belong to the same group
		fmt.Println("Yes") // If yes, print "Yes"
	} else {
		fmt.Println("No") // If not, print "No"
	}
}
