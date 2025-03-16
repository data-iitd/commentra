package main

import (
	"fmt"
)

// Function to check if a year is a leap year
func leapYear(n int) string {
	// Check if the year is a leap year by checking if it satisfies the conditions
	if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
		// If the conditions are met, return "y" to indicate that the year is a leap year
		return "y"
	}
	// If the conditions are not met, return "n" to indicate that the year is not a leap year
	return "n"
}

func main() {
	var n int
	// Take an integer input from the user
	fmt.Scan(&n)

	// Initialize a variable 'd' to keep track of the day of the week for the given year
	d := "f"

	// Check if the given year is a leap year
	var ans string
	if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
		// If the year is a leap year, set the answer to "ly"
		ans = "ly"
	} else {
		// If the year is not a leap year, set the answer to "nly"
		ans = "nly"
	}

	// Keep updating the day of the week and the year until we find the correct answer
	for {
		// Check if the given year is a leap year
		if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
			// If the year is a leap year, update the day of the week accordingly
			switch d {
			case "m":
				d = "w"
				n++
			case "t":
				d = "th"
				n++
			case "w":
				d = "f"
				n++
			case "th":
				d = "sa"
				n++
			case "f":
				d = "s"
				n++
			case "sa":
				d = "m"
				n++
			case "s":
				d = "t"
				n++
			}
		} else {
			// If the year is not a leap year, update the day of the week accordingly
			switch d {
			case "m":
				d = "t"
				n++
			case "t":
				d = "w"
				n++
			case "w":
				d = "th"
				n++
			case "th":
				d = "f"
				n++
			case "f":
				d = "sa"
				n++
			case "sa":
				d = "s"
				n++
			case "s":
				d = "m"
				n++
			}
		}

		// Check if we have found the correct answer
		if d == "f" && ans == "ly" && leapYear(n) == "y" {
			// If we have found the correct answer, break out of the loop
			break
		} else if d == "f" && ans == "nly" && leapYear(n) == "n" {
			// If we have found the correct answer, break out of the loop
			break
		}
	}

	// Print the result
	fmt.Println(n)
}

// <END-OF-CODE>
