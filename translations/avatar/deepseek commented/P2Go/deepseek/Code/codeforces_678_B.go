package main

import (
	"fmt"
)

// Function to check if a year is a leap year
func leapyear(n int) string {
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
		return "y"
	} else {
		return "n"
	}
}

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input from the user
	d := "f" // Initialize the variable d to "f"

	// Determine if the year is a leap year and initialize ans accordingly
	ans := "nly"
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
		ans = "ly"
	}

	// Start an infinite loop to find the next Friday the 13th
	for {
		if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) { // Check if n is a leap year
			switch d {
			case "m":
				d = "w"
				n += 1
			case "t":
				d = "th"
				n += 1
			case "w":
				d = "f"
				n += 1
			case "th":
				d = "sa"
				n += 1
			case "f":
				d = "s"
				n += 1
			case "sa":
				d = "m"
				n += 1
			case "s":
				d = "t"
				n += 1
			}
		} else {
			switch d {
			case "m":
				d = "t"
				n += 1
			case "t":
				d = "w"
				n += 1
			case "w":
				d = "th"
				n += 1
			case "th":
				d = "f"
				n += 1
			case "f":
				d = "sa"
				n += 1
			case "sa":
				d = "s"
				n += 1
			case "s":
				d = "m"
				n += 1
			}
		}

		// Check if the current day is Friday and the year is a leap year or not
		if (d == "f" && ans == "ly" && leapyear(n) == "y") {
			break // Exit the loop if the condition is met
		} else if (d == "f" && ans == "nly" && leapyear(n) == "n") {
			break // Exit the loop if the condition is met
		}
	}

	fmt.Println(n) // Print the final year after finding the next Friday the 13th
}
