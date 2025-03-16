package main // Defining the main package

import (
	"fmt" // Importing the fmt package for input and output
)

func main() { // Defining the main function
	var n, k int // Declaring variables n and k
	fmt.Scan(&n, &k) // Reading the first two integers from the input

	l, c := 0, 1 // Initializing the variables l and c with values 0 and 1 respectively

	for i := 0; i < n; i++ { // Starting a for loop that iterates n times
		var a int // Declaring variable a
		fmt.Scan(&a) // Reading the next integer from the input and assigning it to variable a

		if a == l { // If the current integer is equal to the previous one
			c++ // Increment the counter c by 1
		} else {
			c = 1 // Otherwise, reset the counter c to 1
		}

		l = a // Assigning the current integer to the previous integer variable l
	}

	if c+k > n { // Checking if the sum of counter c and integer k is greater than the total number of integers n
		fmt.Println(n - c) // If true, print the difference between n and c
	} else {
		fmt.Println(-1) // If false, print -1
	}
}

// <END-OF-CODE>
