package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	in := make(chan string)
	go func() {
		for {
			var input string
			fmt.Scanln(&input)
			in <- input
		}
	}()

	// Read the year input from the user
	y := readInt(in)

	// Check if the input year is a leap year
	leap := checkLeap(y)

	// Initialize variables to keep track of the total days and the modulus
	sum := 0
	mod := 0

	// Start an infinite loop to find the next matching year
	for i := y + 1; ; i++ {
		// Check if the current year is a leap year and add the corresponding days to sum
		if checkLeap(i) {
			sum += 366
		} else {
			sum += 365
		}

		// Check if the total number of days is a multiple of 7
		if sum%7 == 0 {
			// If the leap year status matches with the input year, print the year and exit
			if ((checkLeap(i) && leap) || (!checkLeap(i) && !leap)) {
				fmt.Println(i)
				os.Exit(0)
			} else {
				// Continue to the next iteration if the leap year status does not match
				continue
			}
		}
	}
}

// Method to determine if a given year is a leap year
func checkLeap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100 != 0)
}

// Method to read an integer from the user
func readInt(in chan string) int {
	var y int
	var err error
	for {
		y, err = strconv.Atoi(<-in)
		if err == nil {
			break
		}
	}
	return y
}

// 