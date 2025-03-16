
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Reading the year from the user input
	y, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Invalid input")
		return
	}

	// Checking if the year is a leap year
	leap := check_leap(y)

	// Initializing sum to accumulate days
	sum := 0

	// Starting a loop from the next year after 'y' to find the first year where the sum of days is a multiple of 7
	for i := y + 1; ; i++ {
		if check_leap(i) { // Checking if the current year is a leap year
			sum += 366 // Adding 366 days for leap years
		} else {
			sum += 365 // Adding 365 days for non-leap years
		}
		if sum%7 == 0 { // Checking if the sum of days is a multiple of 7
			if (check_leap(i) && leap) || (!check_leap(i) && !leap) { // Checking if the current year's leap status matches the initial leap status
				fmt.Println(i) // Printing the year if it matches
				return
			} else {
				continue // Continuing the loop if the leap status does not match
			}
		}
	}
}

// Method to check if a year is a leap year
func check_leap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100 != 0) // Returning true if the year is a leap year
}

