package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of friends
	fmt.Print("Enter the number of friends: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Arrays to keep track of the number of male and female friends per day
	FfriendPerDay := make([]int, 367) // Array for female friends
	MfriendPerDay := make([]int, 367) // Array for male friends

	// Variable to store the maximum number of friends present on any day
	answer := 0

	// Loop through each friend to gather their availability
	for i := 0; i < n; i++ {
		// Read the gender of the friend (M for male, F for female)
		fmt.Print("Enter the gender of the friend (M for male, F for female): ")
		input, _ := reader.ReadString('\n')
		c := strings.TrimSpace(input)[0]

		// Read the start day (a) and end day (b) of availability
		fmt.Print("Enter the start day (a) and end day (b) of availability: ")
		input, _ = reader.ReadString('\n')
		a, _ := strconv.Atoi(strings.TrimSpace(input))
		b, _ := strconv.Atoi(strings.TrimSpace(input))

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
	fmt.Printf("The maximum number of friends present on any day multiplied by 2 is %d\n", answer*2)
}

