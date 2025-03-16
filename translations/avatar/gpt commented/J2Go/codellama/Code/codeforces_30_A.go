
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin and initialize scanner
	input, _ := os.ReadAll(os.Stdin)
	scanner := strings.Split(string(input), "\n")
	scanner = scanner[:len(scanner)-1]
	scanner = scanner[1:]

	// Iterate through input and solve each case
	for _, line := range scanner {
		// Read input and convert to int
		input := strings.Split(line, " ")
		A, _ := strconv.Atoi(input[0])
		B, _ := strconv.Atoi(input[1])
		n, _ := strconv.Atoi(input[2])

		// Check if A is zero
		if A == 0 {
			// If both A and B are zero, print 1 (indeterminate case)
			if B == 0 {
				fmt.Println(1)
				continue
			}
			// If A is zero and B is not, print "No solution"
			fmt.Println("No solution")
			continue
		}

		// Check if B is not divisible by A
		if B%A != 0 {
			// If B is not divisible by A, print "No solution"
			fmt.Println("No solution")
			continue
		}

		// Divide B by A to simplify the equation
		B /= A

		// Determine if B is negative
		neg := B < 0

		// Check if B is negative and n is even
		if neg && n%2 == 0 {
			// If both conditions are true, print "No solution"
			fmt.Println("No solution")
			continue
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
				continue
			}
		}

		// If no valid x is found, print "No solution"
		fmt.Println("No solution")
	}
}

