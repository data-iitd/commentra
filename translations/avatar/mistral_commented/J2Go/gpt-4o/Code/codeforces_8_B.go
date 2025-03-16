package main

import (
	"fmt"
	"math"
)

func main() {
	var s string
	var x, y, k int
	var flag = true

	fmt.Scan(&s) // Reading the input string from the console
	co := make([][2]int, 101) // Declaring a 2D slice of size 101 x 2

	// Initializing the first element of the array with x and y values
	co[k][0] = x
	co[k][1] = y
	k++ // Incrementing the size of the array

	for i := 0; i < len(s); i++ { // Loop to iterate through each character in the string
		switch s[i] { // Switch statement to handle each character based on its value
		case 'L':
			x-- // Move x to the left
		case 'R':
			x++ // Move x to the right
		case 'U':
			y++ // Move y up
		case 'D':
			y-- // Move y down
		}
		co[k][0] = x // Updating the current position in the array
		co[k][1] = y
		k++ // Incrementing the size of the array
	}

	for i := 0; i < k-3; i++ { // Outer loop to iterate through all elements except the last three
		for j := i + 3; j < k; j++ { // Inner loop to compare the current element with the next three elements
			dx := int(math.Abs(float64(co[i][0] - co[j][0]))) // Calculate the difference in x-coordinates
			dy := int(math.Abs(float64(co[i][1] - co[j][1]))) // Calculate the difference in y-coordinates
			if (dx <= 1 && dy == 0) || (dy <= 1 && dx == 0) { // Checking if the difference is within 1 unit in either x or y direction
				flag = false // Setting the flag to false if a difference of 1 unit is found
				break // Exiting the inner loop if a difference of 1 unit is found
			}
		}
		if !flag {
			break // Exiting the outer loop if a difference of 1 unit is found in any of the inner loops
		}
	}

	if flag {
		fmt.Println("OK") // Printing "OK" if no difference of 1 unit is found
	} else {
		fmt.Println("BUG") // Printing "BUG" if a difference of 1 unit is found
	}
}

// <END-OF-CODE>
