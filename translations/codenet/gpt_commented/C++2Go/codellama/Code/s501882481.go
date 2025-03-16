
package main

import "fmt"

func main() {
	var S string // Variable to store the input weather condition
	fmt.Scan(&S) // Read the weather condition from standard input

	// Determine the next weather condition based on the current one
	if S == "Sunny" {
		fmt.Println("Cloudy") // If it's sunny, print "Cloudy"
	} else if S == "Cloudy" {
		fmt.Println("Rainy") // If it's cloudy, print "Rainy"
	} else {
		fmt.Println("Sunny") // If it's neither, it must be rainy, print "Sunny"
	}
}

