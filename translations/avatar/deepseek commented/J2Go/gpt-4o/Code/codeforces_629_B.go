package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of entries
	FfriendPerDay := make([]int, 367) // Array to store the number of female friends per day
	MfriendPerDay := make([]int, 367) // Array to store the number of male friends per day
	answer := 0 // Variable to store the maximum number of friends on any single day

	// Loop through each entry
	for i := 0; i < n; i++ {
		var c byte
		var a, b int
		fmt.Scanf("%c %d %d\n", &c, &a, &b) // Read the gender (M or F), start day, and end day

		// Update the friend counts for each day in the range
		for j := a; j <= b; j++ {
			if c == 'M' {
				MfriendPerDay[j]++ // Increment male friend count
			} else {
				FfriendPerDay[j]++ // Increment female friend count
			}

			// Determine which gender has the lower count and update the answer
			if MfriendPerDay[j] < FfriendPerDay[j] {
				if MfriendPerDay[j] > answer {
					answer = MfriendPerDay[j] // Update answer if current male count is greater
				}
			} else {
				if FfriendPerDay[j] > answer {
					answer = FfriendPerDay[j] // Update answer if current female count is greater
				}
			}
		}
	}

	// Output the result, which is twice the maximum number of friends on any single day
	fmt.Println(answer * 2)
}

// <END-OF-CODE>
