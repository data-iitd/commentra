package main

import (
	"fmt"
)

func main() {
	var S string // Declare a string variable named S
	fmt.Scan(&S) // Get input for the string variable S

	if S == "Sunny" { // Check if the string is equal to "Sunny"
		fmt.Println("Cloudy") // If true, print "Cloudy"
	} else if S == "Cloudy" { // Check if the string is equal to "Cloudy"
		fmt.Println("Rainy") // If true, print "Rainy"
	} else { // If neither of the conditions are true
		fmt.Println("Sunny") // Print "Sunny"
	}
}

// <END-OF-CODE>
