package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the first integer n, which represents the number of elements in the arrays a and b
	a := make([]int, n) // Create an integer slice a with a length of n
	b := make([]int, n) // Create an integer slice b with a length of n
	temp := 0 // Initialize a variable temp to 0
	q := 0 // Initialize a variable q to 0
	w := math.MinInt32 // Initialize a variable w to the smallest possible integer value
	e := math.MinInt32 // Initialize a variable e to the smallest possible integer value
	f := false // Initialize a boolean variable f to false

	for i := 0; i < n; i++ { // Start a for loop that iterates through the elements of arrays a and b
		fmt.Scan(&a[i]) // Read the next integer value for a[i]
		fmt.Scan(&b[i]) // Read the next integer value for b[i]

		if temp < a[i] { // If the current value of temp is less than a[i]
			if q > b[i] { // Check if the condition q > b[i] is satisfied
				f = true // If it is, set f to true
			}
			q = b[i] // Update q with the new value of b[i]
			temp = a[i] // Update temp with the new value of a[i]
		}

		if temp > a[i] { // If the current value of temp is greater than a[i]
			if q < b[i] { // Check if the condition q < b[i] is satisfied
				f = true // If it is, set f to true
			}
			q = b[i] // Update q with the new value of b[i]
			temp = a[i] // Update temp with the new value of a[i]
		}

		if a[i] > w { // If the current value of a[i] is greater than w
			w = a[i] // Update w with the new value of a[i]
			if b[i] < e { // Check if the condition b[i] < e is satisfied
				f = true // If it is, set f to true
			}
		}

		if a[i] < w { // If the current value of a[i] is less than w
			if b[i] > e { // Check if the condition b[i] > e is satisfied
				f = true // If it is, set f to true
			}
		}
	}

	if f { // After the loop finishes, check the value of the boolean variable f
		fmt.Println("Happy Alex") // If it is true, print the message "Happy Alex"
	} else {
		fmt.Println("Poor Alex") // Otherwise, print the message "Poor Alex"
	}
}

// <END-OF-CODE>
