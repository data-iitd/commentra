package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n) // Read an integer value from the standard input and assign it to variable n

	for i := 1; i <= n; i++ { // Start a for loop that iterates from 1 to n
		x := i // Assign the value of i to variable x
		s := strconv.Itoa(x) // Convert integer x to string s

		if x%3 == 0 || x%10 == 3 { // Check if x is divisible by 3 or its last digit is 3
			fmt.Print(" ", i) // If true, print space followed by i
			continue // Skip the rest of the loop body and move to the next iteration
		} else { // If x is not divisible by 3 and its last digit is not 3
			k := len(s) // Get the size of string s

			for k > 0 { // Start a for loop that runs as long as the size of string s is greater than 0
				k-- // Decrease the size of string s by 1
				j := int(pow(10, float64(k))) // Calculate the value of the power of 10 raised to the power of the current digit position

				if (x/j)%10 == 3 { // Check if the digit in the current position of x is 3
					fmt.Print(" ", i) // If true, print space followed by i
					break // Exit the for loop and move to the next iteration of the outer loop
				}
			}
		}
	}
	fmt.Println() // Print a newline character after the loop is finished
}

// pow function to calculate power of a number
func pow(base, exp float64) float64 {
	return float64(int(base) ^ int(exp))
}
