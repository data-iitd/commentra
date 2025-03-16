package main

import (
	"fmt"
)

func main() {
	// Create a scanner to read input from the console
	var n int
	fmt.Scan(&n)

	// Arrays to keep track of the number of male and female friends per day
	FfriendPerDay := make([]int, 367) // Array for female friends
	MfriendPerDay := make([]int, 367) // Array for male friends

	// Variable to store the maximum number of friends present on any day
	answer := 0

	// Loop through each friend to gather their availability
	for i := 0; i < n; i++ {
		var c byte
		var a, b int
		fmt.Scanf(" %c %d %d", &c, &a, &b)

		// Loop through the days from a to b
		for j := a; j <= b; j++ {
			// Increment the count for male or female friends based on gender
			if c == 'M' {
				MfriendPerDay[j]++
			} else {
				FfriendPerDay[j]++
			}

			// Check which gender has more friends on that day and update the answer
			if MfriendPerDay[j] < FfriendPerDay[j] {
				// If females are more, check if their count is greater than the current answer
				if MfriendPerDay[j] > answer {
					answer = MfriendPerDay[j]
				}
			} else {
				// If males are more or equal, check if their count is greater than the current answer
				if FfriendPerDay[j] > answer {
					answer = FfriendPerDay[j]
				}
			}
		}
	}

	// Output the maximum number of friends present on any day multiplied by 2
	fmt.Println(answer * 2)
}

// <END-OF-CODE>
