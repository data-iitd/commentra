package main

import (
	"fmt"
)

func main() {
	// Declaring variables for pandu, vundu, urdu and counter c
	var pandu, vundu, urdu int64
	c := int64(0)

	// Reading the values of pandu, vundu and urdu from the console
	fmt.Scan(&pandu, &vundu, &urdu)

	// Using a for loop to calculate the sum of the series and store it in the variable c
	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
		// Comment: Calculating the sum of the series using the formula: c = c + i * pandu
	}

	// Checking if the calculated sum is less than vundu
	if c < vundu {
		// Comment: If the calculated sum is less than vundu, then print "0"
		fmt.Print("0")
	} else {
		// Comment: If the calculated sum is greater than or equal to vundu, then print the difference between the calculated sum and vundu
		fmt.Print(c - vundu)
	}
}

// <END-OF-CODE>
