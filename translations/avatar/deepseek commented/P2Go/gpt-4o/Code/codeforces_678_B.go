package main

import (
	"fmt"
)

func leapYear(n int) string { // Function to check if a year is a leap year
	if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
		return "y"
	}
	return "n"
}

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input from the user
	d := "f"     // Initialize the variable d to "f"

	// Determine if the year is a leap year and initialize ans accordingly
	var ans string
	if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
		ans = "ly"
	} else {
		ans = "nly"
	}

	// Start an infinite loop to find the next Friday the 13th
	for {
		if n%400 == 0 || (n%4 == 0 && n%100 != 0) { // Check if n is a leap year
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

		// Check if the current day is Friday and the year is a leap year or not
		if d == "f" && ans == "ly" && leapYear(n) == "y" {
			break // Exit the loop if the condition is met
		} else if d == "f" && ans == "nly" && leapYear(n) == "n" {
			break // Exit the loop if the condition is met
		}
	}

	fmt.Println(n) // Print the final year after finding the next Friday the 13th
}

// <END-OF-CODE>
