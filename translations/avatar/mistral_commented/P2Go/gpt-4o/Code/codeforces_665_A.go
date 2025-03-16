package main

import (
	"fmt"
)

func main() {
	var a, at int
	fmt.Scan(&a, &at) // Read the first pair of integers (a and at)

	var b, bt int
	fmt.Scan(&b, &bt) // Read the second pair of integers (b and bt)

	var t1, t2 int
	fmt.Scanf("%d:%d", &t1, &t2) // Read the start time (t1) and end time (t2) from the user input in the format "HH:MM"

	st := t2 + (t1-5)*60 // Calculate the start time in seconds
	fin := st + at       // Calculate the finish time in seconds

	now := 0 // Initialize the current time to zero
	ans := 0 // Initialize the answer to zero

	// Loop through the time until the current time is less than the finish time and less than 1140 (11:00 PM)
	for now < fin && now < 1140 {
		// If the next event starts after the current time, increment the answer
		if now+bt > st {
			ans++
		}
		// Increment the current time by the duration of the next event
		now += b
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
