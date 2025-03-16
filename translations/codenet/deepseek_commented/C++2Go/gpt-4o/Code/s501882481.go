package main

import (
	"fmt"
)

// Utility function to print a single item.
func print(args ...interface{}) {
	fmt.Println(args...)
}

// Main function to execute the program.
func main() {
	var S string
	fmt.Scan(&S)
	if S == "Sunny" {
		print("Cloudy")
	} else if S == "Cloudy" {
		print("Rainy")
	} else {
		print("Sunny")
	}
}

// <END-OF-CODE>
