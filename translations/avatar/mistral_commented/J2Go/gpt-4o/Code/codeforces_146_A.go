package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the integer value of n from the standard input

	var str string
	fmt.Scan(&str) // Reading the string value of the input from the standard input

	t := 0 // Declaring and initializing an integer variable t

	// Checking if all characters are either '4' or '7'
	for i := 0; i < n; i++ {
		if str[i] != '4' && str[i] != '7' {
			t = 1 // Setting the value of t to 1 if the condition is true
			break
		}
	}

	if t == 1 { // Checking if the value of t is equal to 1
		fmt.Println("NO") // Printing "NO" if the condition is true
	} else { // Else part of the if statement
		sumX := 0 // Declaring and initializing an integer variable sumX to store the sum of the digits in the first half of the string
		sumY := 0 // Declaring and initializing an integer variable sumY to store the sum of the digits in the second half of the string

		// Iterating through the first half of the string to calculate the sum of its digits
		for i := 0; i < n/2; i++ {
			sumX += int(str[i] - '0') // Adding the value of the current digit to sumX
		}

		// Iterating through the second half of the string to calculate the sum of its digits
		for i := n - 1; i >= n/2; i-- {
			sumY += int(str[i] - '0') // Adding the value of the current digit to sumY
		}

		if sumX == sumY { // Checking if the sum of digits in the first half is equal to the sum of digits in the second half
			fmt.Println("YES") // Printing "YES" if the condition is true
		} else { // Else part of the if statement
			fmt.Println("NO") // Printing "NO" if the condition is false
		}
	}
}

// <END-OF-CODE>
