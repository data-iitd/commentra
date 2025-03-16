package main

import (
	"fmt"
	"math"
)

func main() {
	var A, B, n int
	fmt.Scan(&A, &B, &n) // Reading the first three integer values from the standard input

	if A == 0 {
		if B == 0 {
			fmt.Println(1) // If both A and B are zero, print 1
		} else {
			fmt.Println("No solution") // If A is zero but B is not, print "No solution"
		}
		return // Exit the function
	}

	if B%A != 0 {
		fmt.Println("No solution") // If B is not divisible by A, print "No solution"
		return // Exit the function
	}

	B /= A // Dividing B by A
	neg := B < 0 // Checking if B is negative

	if neg && n%2 == 0 {
		fmt.Println("No solution") // If both conditions are true, print "No solution"
		return // Exit the function
	}

	if neg {
		B = -B // If B is negative, make it positive
	}

	for x := 0; x <= B; x++ { // Iterating through all possible values of x from 0 to B
		if math.Pow(float64(x), float64(n)) == float64(B) { // Checking if x raised to the power of n is equal to B
			if neg {
				fmt.Println(-x) // Printing the value of x with its sign
			} else {
				fmt.Println(x) // Printing the value of x
			}
			return // Exit the function
		}
	}

	fmt.Println("No solution") // If no solution is found, print "No solution"
}

// <END-OF-CODE>
