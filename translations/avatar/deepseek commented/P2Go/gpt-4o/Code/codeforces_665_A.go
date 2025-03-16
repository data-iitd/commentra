package main

import (
	"fmt"
)

func main() {
	var a, at int
	fmt.Scan(&a, &at) // Reading two integers

	var b, bt int
	fmt.Scan(&b, &bt) // Reading two more integers

	var t1, t2 int
	fmt.Scanf("%d:%d", &t1, &t2) // Reading time in "HH:MM" format

	// Calculate the start time by adjusting t1 by subtracting 5 hours and converting to minutes, then adding t2
	st := t2 + (t1-5)*60

	// Calculate the finish time by adding at to the start time
	fin := st + at

	// Initialize now and ans variables
	now := 0
	ans := 0

	// Loop until now is less than fin and now is less than 1140
	for now < fin && now < 1140 {
		if now+bt > st { // Check if adding bt to now would exceed the start time
			ans++ // Increment ans if the condition is met
		}
		now += b // Increment now by b
	}

	// Print the final value of ans
	fmt.Println(ans)
}

// <END-OF-CODE>
