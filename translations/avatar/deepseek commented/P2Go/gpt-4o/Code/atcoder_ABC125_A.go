package main

import (
	"fmt"
)

func main() {
	var a, b, t int
	// Taking three inputs from the user: a, b, and t
	fmt.Scan(&a, &b, &t)

	cookie := 0
	// Initializing the cookie count to 0
	time := a
	// Setting the initial time to the value of a

	for time <= t+1 {
		// The loop continues as long as time is less than or equal to t + 0.5
		cookie += b
		// Incrementing the cookie count by b
		time += a
		// Incrementing the time by a
	}

	fmt.Println(cookie)
	// Printing the final cookie count after the loop finishes
}

// <END-OF-CODE>
