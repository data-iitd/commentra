package main

import (
	"fmt"
	"time"
)

func main() {
	// Create a Scanner object to read input from the user
	var y int
	fmt.Scan(&y)
	
	// Check if the input year is a leap year
	leap := isLeap(y)
	
	// Initialize variables to keep track of the total days and the modulus
	sum := 0
	mod := 0
	
	// Start an infinite loop to find the next matching year
	for i := y + 1; ; i++ {
		// Check if the current year is a leap year and add the corresponding days to sum
		if isLeap(i) {
			sum += 366
		} else {
			sum += 365
		}
		
		// Check if the total number of days is a multiple of 7
		if sum % 7 == 0 {
			// If the leap year status matches with the input year, print the year and exit
			if (isLeap(i) && leap) || (!isLeap(i) && !leap) {
				fmt.Println(i)
				return
			} else {
				// Continue to the next iteration if the leap year status does not match
				continue
			}
		}
	}
}

// Method to determine if a given year is a leap year
func isLeap(y int) bool {
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)
}

