
package main

import "fmt"

func main() {
	// Declare a variable named day of type int
	var day int

	// Read an integer value from the standard input using fmt.Scan()
	fmt.Scan(&day)

	// Use a switch statement to determine the name of the day based on the given day number
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
