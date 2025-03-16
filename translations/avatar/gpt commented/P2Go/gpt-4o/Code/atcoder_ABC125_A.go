package main

import (
	"fmt"
)

func main() {
	// Read input values for 'a', 'b', and 't' from the user
	var a, b, t int
	fmt.Scan(&a, &b, &t)

	// Initialize the cookie count to zero
	cookie := 0

	// Set the initial time to 'a'
	time := float64(a)

	// Loop until the time exceeds 't + 0.5'
	for time <= float64(t)+0.5 {
		// Add 'b' cookies for each time interval
		cookie += b
		// Increment the time by 'a' for the next iteration
		time += float64(a)
	}

	// Print the total number of cookies collected
	fmt.Println(cookie)
}

// <END-OF-CODE>
