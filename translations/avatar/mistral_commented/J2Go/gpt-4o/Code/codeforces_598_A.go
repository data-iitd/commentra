package main // Defining the main package

import (
	"fmt" // Importing the fmt package for input and output
	"math" // Importing the math package for mathematical functions
)

func main() { // Defining the main function
	var q int
	fmt.Scan(&q) // Reading the number of test cases from the console

	for q > 0 { // Starting a for loop that runs q times
		q-- // Decrementing the number of test cases

		var n int
		fmt.Scan(&n) // Reading the integer 'n' from the console

		var s int64 = 0 // Initializing the int64 variable 's' with zero value

		x := int(math.Log2(float64(n))) // Calculating the integer 'x' using the logarithmic formula
		x++ // Incrementing the value of 'x' by 1

		s = -1*int64(math.Pow(2, float64(x))) + 2 + (int64(n)*int64(n+1))/2 - int64(math.Pow(2, float64(x))) // Calculating the value of 's' using the given formula

		fmt.Println(s) // Printing the value of 's' to the console
	}
}

// <END-OF-CODE>
