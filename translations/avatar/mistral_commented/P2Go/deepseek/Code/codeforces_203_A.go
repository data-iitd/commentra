package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Input the string of numbers separated by spaces and split it into a list
	var input string
	fmt.Scanln(&input)
	xxs := strings.Split(input, " ")

	// Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
	x, _ := strconv.Atoi(xxs[0])
	t, _ := strconv.Atoi(xxs[1])
	a, _ := strconv.Atoi(xxs[2])
	b, _ := strconv.Atoi(xxs[3])
	da, _ := strconv.Atoi(xxs[4])
	db, _ := strconv.Atoi(xxs[5])

	// Define the main function to perform the logic of the program
	mainLogic := func() string {
		// Check if x is equal to zero
		if x == 0 {
			return "YES"
		}

		// Calculate the minimum time it takes for a and b to reach x
		aTime := min(a/da, t-1)
		bTime := min(b/db, t-1)

		// Loop through all possible combinations of a_time and b_time
		for i := 0; i <= aTime; i++ {
			for j := 0; j <= bTime; j++ {
				// Check if x is equal to a after 'i' time steps or b after 'j' time steps
				if a-da*i == x || b-db*j == x {
					return "YES"
				}

				// Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
				if (a-da*i)+(b-db*j) == x {
					return "YES"
				}
			}
		}
		return "NO"
	}

	// Call the main function and assign the result to a variable ff
	ff := mainLogic()

	// Print the result
	fmt.Println(ff)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

