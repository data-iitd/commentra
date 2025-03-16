package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Reading the first and second integer inputs from the user

	// Checking if the first number is positive
	if a > 0 {
		fmt.Println("Positive") // Printing "Positive" if the first number is greater than 0
	} else if b >= 0 {
		fmt.Println("Zero") // Printing "Zero" if the second number is non-negative
	} else if (b-a+1)%2 == 0 {
		fmt.Println("Positive") // Printing "Positive" if the difference is even
	} else {
		fmt.Println("Negative") // Printing "Negative" if none of the above conditions are met
	}
}
