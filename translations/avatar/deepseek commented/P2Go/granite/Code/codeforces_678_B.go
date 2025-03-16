
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func leapyear(n int) string {  // Function to check if a year is a leap year
	if (n%400 == 0 || (n%4 == 0 && n%100!= 0)) {
		return "y"
	} else {
		return "n"
	}
}

func main() {
	var n int  // Declare and initialize the variable n
	var d string  // Declare and initialize the variable d

	// Read an integer input from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter an integer: ")
	text, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(text)

	// Determine if the year is a leap year and initialize ans accordingly
	var ans string
	if (n%400 == 0 || (n%4 == 0 && n%100!= 0)) {
		ans = "ly"
	} else {
		ans = "nly"
	}

	// Start an infinite loop to find the next Friday the 13th
	for {
		if (n%400 == 0 || (n%4 == 0 && n%100!= 0)) {  // Check if n is a leap year
			if (d == "m") {  // Update d and n based on the current day
				d = "w"
				n++
			} else if (d == "t") {
				d = "th"
				n++
			} else if (d == "w") {
				d = "f"
				n++
			} else if (d == "th") {
				d = "sa"
				n++
			} else if (d == "f") {
				d = "s"
				n++
			} else if (d == "sa") {
				d = "m"
				n++
			} else if (d == "s") {
				d = "t"
				n++
			}
		} else {
			if (d == "m") {
				d = "t"
				n++
			} else if (d == "t") {
				d = "w"
				n++
			} else if (d == "w") {
				d = "th"
				n++
			} else if (d == "th") {
				d = "f"
				n++
			} else if (d == "f") {
				d = "sa"
				n++
			} else if (d == "sa") {
				d = "s"
				n++
			} else if (d == "s") {
				d = "m"
				n++
			}
		}

		// Check if the current day is Friday and the year is a leap year or not
		if (d == "f" && ans == "ly" && leapyear(n) == "y") {
			break  // Exit the loop if the condition is met
		} else if (d == "f" && ans == "nly" && leapyear(n) == "n") {
			break  // Exit the loop if the condition is met
		}
	}

	fmt.Println(n)  // Print the final year after finding the next Friday the 13th
}

