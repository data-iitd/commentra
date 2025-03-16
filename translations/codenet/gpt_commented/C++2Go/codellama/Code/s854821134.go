package main

import "fmt"

func main() {
	var a, b int // Declare two integer variables a and b
	fmt.Scan(&a, &b) // Read two integer inputs from the user

	// Check if both a and b are less than or equal to 8
	if a <= 8 && b <= 8 {
		fmt.Println("Yay!") // If true, print "Yay!"
	} else {
		fmt.Println(":(") // If false, print ":("
	}
}

