package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of friends
	scanner.Scan()
	n := 0
	fmt.Sscanf(scanner.Text(), "%d", &n)
	
	// Arrays to keep track of the number of male and female friends per day
	FfriendPerDay := make([]int, 367) // Array for female friends
	MfriendPerDay := make([]int, 367) // Array for male friends
	
	// Variable to store the maximum number of friends present on any day
	answer := 0
	
	// Loop through each friend to gather their availability
	for i := 0; i < n; i++ {
		// Read the gender of the friend (M for male, F for female)
		var c string
		scanner.Scan()
		c = scanner.Text()
		
		// Read the start day (a) and end day (b) of availability
		var a, b int
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d", &a, &b)
		
		// Loop through the days from a to b
		for j := a; j <= b; j++ {
			// Increment the count for male or female friends based on gender
			if c[0] == 'M' {
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

