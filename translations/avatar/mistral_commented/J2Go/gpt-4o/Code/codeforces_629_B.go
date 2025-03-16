package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of test cases

	FfriendPerDay := make([]int, 367) // Initializing a slice of size 367 to store the number of friends of type F for each day
	MfriendPerDay := make([]int, 367) // Initializing a slice of size 367 to store the number of friends of type M for each day
	answer := 0 // Initializing an integer variable to store the maximum difference between the number of friends of type F and M for any day

	for i := 0; i < n; i++ { // Iterating through each test case
		var c byte
		var a, b int
		fmt.Scanf(" %c %d %d", &c, &a, &b) // Reading the character representing the gender of the friend and the starting and ending days

		for j := a; j <= b; j++ { // Iterating through each day in the range
			if c == 'M' {
				MfriendPerDay[j]++ // Incrementing the counter in the MfriendPerDay slice for the day if the friend is of type M
			} else {
				FfriendPerDay[j]++ // Incrementing the counter in the FfriendPerDay slice for the day if the friend is of type F
			}

			if MfriendPerDay[j] < FfriendPerDay[j] { // Checking if the number of friends of type M is less than the number of friends of type F for the current day
				if MfriendPerDay[j] > answer {
					answer = MfriendPerDay[j] // Updating the value of answer if the current difference is greater than the previous maximum difference
				}
			} else { // Repeating the same check for the number of friends of type F
				if FfriendPerDay[j] > answer {
					answer = FfriendPerDay[j]
				}
			}
		}
	}

	fmt.Println(answer * 2) // Printing the answer, which is twice the maximum difference between the number of friends of type F and M for any day.
}

// <END-OF-CODE>
