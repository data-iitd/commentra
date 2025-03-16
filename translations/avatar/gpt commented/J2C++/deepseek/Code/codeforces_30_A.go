package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	// Create a new instance of Main and call the solve method with a Scanner for input
	solve(os.Stdin)
}

func solve(sc *os.File) {
	// Read three integers A, B, and n from the input
	var A, B, n int
	fmt.Fscan(sc, &A, &B, &n)
	
	// Check if A is zero
	if A == 0 {
		// If both A and B are zero, print 1 (indeterminate case)
		if B == 0 {
			fmt.Println(1)
		} else {
			// If A is zero and B is not, print "No solution"
			fmt.Println("No solution")
		}
		return
	}
	
	// Check if B is not divisible by A
	if B % A != 0 {
		// If B is not divisible by A, print "No solution"
		fmt.Println("No solution")
		return
	}
	
	// Divide B by A to simplify the equation
	B /= A
	
	// Determine if B is negative
	neg := B < 0
	
	// Check if B is negative and n is even
	if neg && n % 2 == 0 {
		// If both conditions are true, print "No solution"
		fmt.Println("No solution")
		return
	}
	
	// If B is negative, make it positive for further calculations
	if neg {
		B = -B
	}
	
	// Iterate through possible values of x from 0 to B
	for x := 0; x <= B; x++ {
		// Check if x raised to the power of n equals B
		if math.Pow(float64(x), float64(n)) == float64(B) {
			// If found, print the result considering the sign of B
			if neg {
				fmt.Println(-x)
			} else {
				fmt.Println(x)
			}
			return
		}
	}
	
	// If no valid x is found, print "No solution"
	fmt.Println("No solution")
}
