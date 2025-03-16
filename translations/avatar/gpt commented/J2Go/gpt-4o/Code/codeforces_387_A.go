package main

import (
	"fmt"
	"time"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t) // Reading two time inputs in "HH:MM" format

	// Parsing the input strings into time.Time objects
	x, _ := time.Parse("15:04", s)
	y, _ := time.Parse("15:04", t)

	// Calculating the difference between the two times
	diff := x.Sub(y)

	// Printing the result in the format of hours and minutes
	fmt.Printf("%v\n", diff)
}

// <END-OF-CODE>
