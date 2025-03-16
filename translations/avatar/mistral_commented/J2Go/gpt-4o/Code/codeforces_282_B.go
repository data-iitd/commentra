package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of test cases

	// Allocating a slice to store characters
	ch := make([]rune, n)
	s1, s2 := 0, 0 // Initializing two variables to keep track of the sum of x and y coordinates
	j, flag := 0, 0 // Declaring and initializing variables

	// Reading input for each test case
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y) // Reading the values of 'x' and 'y' for the current test case

		temp1 := s1 + x // Calculating the sum of 's1' and 'x'
		temp2 := s2 + y // Calculating the sum of 's2' and 'y'

		// Checking if the difference between the sums is within the limit of 500
		if math.Abs(float64(temp1-temp2)) <= 500 {
			s1 += x // Updating the value of 's1'
			ch[j] = 'A' // Adding 'A' to the character slice 'ch'
			j++ // Incrementing the index
			continue // Skipping the rest of the loop and moving to the next iteration
		}

		// Checking if the difference between the absolute values of the sums is within the limit of 500
		if math.Abs(float64(temp1-s2)) <= 500 {
			s2 += y // Updating the value of 's2'
			ch[j] = 'G' // Adding 'G' to the character slice 'ch'
			j++ // Incrementing the index
			continue // Skipping the rest of the loop and moving to the next iteration
		}

		flag = 1 // Setting the flag to 1 if the difference between the sums is greater than 500
		break // Exiting the loop if the difference is greater than 500
	}

	// Checking if the flag is set to 1, indicating that the difference between the sums is greater than 500 for the current test case
	if flag == 1 {
		fmt.Println(-1) // Printing -1 if the difference is greater than 500
	} else {
		ans := string(ch[:j]) // Converting the character slice 'ch' to a string 'ans'
		fmt.Println(ans) // Printing the string 'ans' as the answer for the current test case
	}
}

// <END-OF-CODE>
