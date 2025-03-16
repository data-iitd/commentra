package main

import (
	"fmt"
)

func main() {
	// Read input values a, b, and t from the user
	var a, b, t int
	fmt.Scan(&a, &b, &t)

	// Initialize cookie counter to 0
	cookie := 0
	// Set initial time to a
	time := a

	// Cookies are produced every 'a' time units, with each production adding 'b' cookies
	// The loop runs as long as the time for production is less than or equal to the total time 't' plus half a time unit
	for float64(time) <= float64(t)+0.5 {
		// Increment cookie counter by 'b'
		cookie += b
		// Update time for next production
		time += a
	}

	// Print the total number of cookies produced
	fmt.Println(cookie)
}

// <END-OF-CODE>
