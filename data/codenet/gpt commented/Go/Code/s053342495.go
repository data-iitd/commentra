package main

import "fmt"

func main() {
	// Declare a variable to hold the day of the month
	var day int
	
	// Read an integer input from the user representing the day
	fmt.Scan(&day)

	// Use a switch statement to determine the holiday based on the day
	switch day {
	case 25:
		// If the day is 25, print "Christmas"
		fmt.Println("Christmas")
	case 24:
		// If the day is 24, print "Christmas Eve"
		fmt.Println("Christmas Eve")
	case 23:
		// If the day is 23, print "Christmas Eve Eve"
		fmt.Println("Christmas Eve Eve")
	case 22:
		// If the day is 22, print "Christmas Eve Eve Eve"
		fmt.Println("Christmas Eve Eve Eve")
	}
}
