package main

import (
	"fmt"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y) // Take two integers as input from the user and store them in x and y respectively
	a := 0           // Initialize the variable a to 0

	for (x >= 0 && y >= 22) || (x >= 1 && y >= 12) || (x >= 2 && y >= 2) { // Run the loop as long as certain conditions are met
		if a == 1 { // If a is true
			if y >= 22 { // Check if y is greater than or equal to 22
				y -= 22 // If so, reduce y by 22
			} else if x >= 1 && y >= 12 { // Else if x is greater than or equal to 1 and y is greater than or equal to 12
				x -= 1  // Reduce x by 1
				y -= 12 // Reduce y by 12
			} else { // Else, x is greater than or equal to 2 and y is greater than or equal to 2
				x -= 2 // Reduce x by 2
				y -= 2 // Reduce y by 2
			}
		} else { // If a is false
			if x >= 2 && y >= 2 { // Check if x is greater than or equal to 2 and y is greater than or equal to 2
				x -= 2 // Reduce x by 2
				y -= 2 // Reduce y by 2
			} else if x >= 1 && y >= 12 { // Else if x is greater than or equal to 1 and y is greater than or equal to 12
				x -= 1  // Reduce x by 1
				y -= 12 // Reduce y by 12
			} else { // Else, y is greater than or equal to 22
				y -= 22 // Reduce y by 22
			}
		}
		a = 1 - a // Toggle the value of a
	}

	if a == 1 {
		fmt.Println("Ciel") // Print "Ciel" if a is 1
	} else {
		fmt.Println("Hanako") // Print "Hanako" if a is 0
	}
}

// <END-OF-CODE>
