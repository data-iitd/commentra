package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read the number of digits and the number of constraints

	s := make([]int, m) // Declare a slice to store the positions of constraints
	c := make([]int, m) // Declare a slice to store the values of constraints

	for i := 0; i < m; i++ {
		fmt.Scan(&s[i], &c[i]) // Read the position and value of each constraint
		s[i]-- // Decrement the position by 1 to convert to 0-based index
	}

	for i := 0; i < 1000; i++ {
		st := strconv.Itoa(i) // Convert the current number to a string
		if len(st) != n { // Check if the length of the string is equal to the number of digits
			continue // If not, continue to the next iteration
		}

		f := true // Initialize a flag to true
		for j := 0; j < m; j++ {
			if st[s[j]] == strconv.Itoa(c[j])[0] { // Check if the digit at the constraint position matches the constraint value
				// Do nothing (continue to the next iteration)
			} else {
				f = false // If any constraint is not met, set the flag to false
			}
		}
		if f { // Check if all constraints are met
			fmt.Println(i) // Print the valid number
			return // Exit the program
		}
	}
	fmt.Println(-1) // If no valid number is found, print -1
}

// <END-OF-CODE>
