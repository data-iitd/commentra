package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read input values and split them into a slice
	var input string
	fmt.Scanln(&input)
	xxs := strings.Split(input, " ")

	// Convert the input strings to integers
	x, _ := strconv.Atoi(xxs[0])
	t, _ := strconv.Atoi(xxs[1])
	a, _ := strconv.Atoi(xxs[2])
	b, _ := strconv.Atoi(xxs[3])
	da, _ := strconv.Atoi(xxs[4])
	db, _ := strconv.Atoi(xxs[5])

	// Check if the target value x is zero
	if x == 0 {
		fmt.Println("YES") // If x is zero, print "YES"
		return
	}

	// Calculate the maximum time available for a and b, constrained by t
	aTime := min(a/da, t-1)
	bTime := min(b/db, t-1)

	// Iterate through all possible values of i and j within the calculated time limits
	for i := 0; i <= aTime; i++ {
		for j := 0; j <= bTime; j++ {
			// Check if either a or b can be reduced to x by subtracting multiples of da or db
			if a-da*i == x || b-db*j == x {
				fmt.Println("YES") // If found, print "YES"
				return
			}
			// Check if the sum of the remaining values of a and b equals x
			if (a-da*i)+(b-db*j) == x {
				fmt.Println("YES") // If found, print "YES"
				return
			}
		}
	}

	// If no valid combination is found, print "NO"
	fmt.Println("NO")
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
