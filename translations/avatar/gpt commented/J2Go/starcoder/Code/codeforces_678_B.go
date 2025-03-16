package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the year input from stdin
	fmt.Print("Enter a year: ")
	year, _ := reader.ReadString('\n')

	// Convert the input string to an integer
	yearInt, _ := strconv.Atoi(strings.TrimSpace(year))

	// Check if the input year is a leap year
	leap := checkLeap(yearInt)

	// Initialize variables to keep track of the total days and the modulus
	sum := 0
	mod := 0

	// Start an infinite loop to find the next matching year
	for {
		// Check if the current year is a leap year and add the corresponding days to sum
		if checkLeap(yearInt) {
			sum += 366
		} else {
			sum += 365
		}

		// Check if the total number of days is a multiple of 7
		if sum%7 == 0 {
			// If the leap year status matches with the input year, print the year and exit
			if (checkLeap(yearInt) && leap) || (!checkLeap(yearInt) &&!leap) {
				fmt.Println(yearInt)
				return
			} else {
				// Continue to the next iteration if the leap year status does not match
				continue
			}
		}

		// Increment the year
		yearInt++
	}
}

// Method to determine if a given year is a leap year
func checkLeap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100!= 0)
}

