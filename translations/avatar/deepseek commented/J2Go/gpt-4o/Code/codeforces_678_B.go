package main

import (
	"fmt"
)

func main() {
	var y int
	fmt.Scan(&y) // Reading the year from the user input
	leap := checkLeap(y) // Checking if the year is a leap year
	sum := 0 // Initializing sum to accumulate days

	// Starting a loop from the next year after 'y' to find the first year where the sum of days is a multiple of 7
	for i := y + 1; ; i++ {
		if checkLeap(i) { // Checking if the current year is a leap year
			sum += 366 // Adding 366 days for leap years
		} else {
			sum += 365 // Adding 365 days for non-leap years
		}
		if sum%7 == 0 { // Checking if the sum of days is a multiple of 7
			if (checkLeap(i) && leap) || (!checkLeap(i) && !leap) { // Checking if the current year's leap status matches the initial leap status
				fmt.Println(i) // Printing the year if it matches
				return // Exiting the program after printing the year
			}
		}
	}
}

// Function to check if a year is a leap year
func checkLeap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100 != 0) // Returning true if the year is a leap year
}

// <END-OF-CODE>
