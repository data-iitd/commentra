package main

import (
	"fmt"
)

func leapYear(n int) string {
	// Determine if the given year n is a leap year
	if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
		return "y" // Return 'y' if it is a leap year
	}
	return "n" // Return 'n' if it is not a leap year
}

func main() {
	var n int
	fmt.Scan(&n) // Read an integer input from the user representing the year

	d := "f" // Initialize the day variable to 'f' (Friday)
	var ans string

	// Check if the initial year n is a leap year and set the answer accordingly
	if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
		ans = "ly" // 'ly' indicates leap year
	} else {
		ans = "nly" // 'nly' indicates non-leap year
	}

	// Infinite loop to determine the next occurrence of a specific day
	for {
		// If the current year n is a leap year
		if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
			// Update the day variable and increment the year based on the current day
			switch d {
			case "m":
				d = "w" // Monday to Wednesday
				n++
			case "t":
				d = "th" // Tuesday to Thursday
				n++
			case "w":
				d = "f" // Wednesday to Friday
				n++
			case "th":
				d = "sa" // Thursday to Saturday
				n++
			case "f":
				d = "s" // Friday to Sunday
				n++
			case "sa":
				d = "m" // Saturday to Monday
				n++
			case "s":
				d = "t" // Sunday to Tuesday
				n++
			}
		} else {
			// If the current year n is not a leap year, update the day variable accordingly
			switch d {
			case "m":
				d = "t" // Monday to Tuesday
				n++
			case "t":
				d = "w" // Tuesday to Wednesday
				n++
			case "w":
				d = "th" // Wednesday to Thursday
				n++
			case "th":
				d = "f" // Thursday to Friday
				n++
			case "f":
				d = "sa" // Friday to Saturday
				n++
			case "sa":
				d = "s" // Saturday to Sunday
				n++
			case "s":
				d = "m" // Sunday to Monday
				n++
			}
		}

		// Check if we have reached a Friday and the leap year condition matches the answer
		if d == "f" && ans == "ly" && leapYear(n) == "y" {
			break // Exit the loop if it's a leap year and it's Friday
		} else if d == "f" && ans == "nly" && leapYear(n) == "n" {
			break // Exit the loop if it's not a leap year and it's Friday
		}
	}

	// Print the resulting year
	fmt.Println(n)
}

// <END-OF-CODE>
