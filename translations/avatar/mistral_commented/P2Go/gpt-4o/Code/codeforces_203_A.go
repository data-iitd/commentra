package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Input the string of numbers separated by spaces and split it into a slice
	var input string
	fmt.Scanln(&input)
	xxs := strings.Fields(input)

	// Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
	x, _ := strconv.Atoi(xxs[0])
	t, _ := strconv.Atoi(xxs[1])
	a, _ := strconv.Atoi(xxs[2])
	b, _ := strconv.Atoi(xxs[3])
	da, _ := strconv.Atoi(xxs[4])
	db, _ := strconv.Atoi(xxs[5])

	// Check if x is equal to zero
	if x == 0 {
		// If yes, print "YES" and return
		fmt.Println("YES")
		return
	}

	// Calculate the minimum time it takes for a and b to reach x
	aTime := min(a/da, t-1)
	bTime := min(b/db, t-1)

	// Loop through all possible combinations of aTime and bTime
	for i := 0; i <= aTime; i++ {
		for j := 0; j <= bTime; j++ {
			// Check if x is equal to a after 'i' time steps or b after 'j' time steps
			if a-da*i == x || b-db*j == x {
				// If yes, print "YES" and return
				fmt.Println("YES")
				return
			}

			// Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
			if (a-da*i)+(b-db*j) == x {
				// If yes, print "YES" and return
				fmt.Println("YES")
				return
			}
		}
	}

	// If no result found, print "NO"
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
