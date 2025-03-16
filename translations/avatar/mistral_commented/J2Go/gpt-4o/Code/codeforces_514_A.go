package main

import (
	"fmt"
	"math"
)

func main() {
	var x int64
	fmt.Scan(&x) // Reading the first number from the standard input stream

	list := []int64{} // Creating an empty slice to store digits

	// The following loop runs as long as the number x is greater than zero
	for x > 0 {
		r := x % 10 // Storing the last digit of the number x in the variable r

		// The following if statement checks if the difference between 9 and the last digit r is less than r itself
		if 9-r < r {
			// The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
			if x/10 == 0 && 9-r == 0 {
				list = append(list, r) // Adding the last digit r to the slice if it is the only digit in the number x
			} else {
				list = append(list, 9-r) // Adding the number 9 minus the last digit r to the slice
			}
		} else {
			list = append(list, r) // Adding the last digit r to the slice
		}

		x = x / 10 // Dividing the number x by 10 to get the next digit
	}

	pow := 0 // Initializing the variable pow to 0 to be used as the power of 10
	newNumber := int64(0) // Initializing the variable newNumber to 0 to store the final number

	// The following loop runs through each digit in the slice and calculates the new number
	for i := 0; i < len(list); i++ {
		newNumber += list[i] * int64(math.Pow(10, float64(pow)))
		pow++
	}

	fmt.Println(newNumber) // Printing the final number to the standard output stream
}

// <END-OF-CODE>
