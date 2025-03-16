package main

import (
	"fmt"
)

func main() {
	// Declaring variables to hold input values and a counter
	var pandu, vundu, urdu int64
	c := int64(0)

	// Reading three long integer values from user input
	fmt.Scan(&pandu) // The first input value
	fmt.Scan(&vundu) // The second input value
	fmt.Scan(&urdu)  // The third input value

	// Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
	for i := int64(1); i <= urdu; i++ {
		c += i * pandu // Incrementing 'c' by the product of 'i' and 'pandu'
	}

	// Checking if the calculated sum 'c' is less than 'vundu'
	if c < vundu {
		fmt.Print("0") // If true, print "0"
	} else {
		// If 'c' is greater than or equal to 'vundu', print the difference
		fmt.Print(c - vundu)
	}
}

// <END-OF-CODE>
