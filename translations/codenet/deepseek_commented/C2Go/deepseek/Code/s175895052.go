package main

import (
	"fmt"
)

func main() {
	var n [4]rune  // Declare a rune array to store the input string
	fmt.Scan(&n[0], &n[1], &n[2], &n[3])  // Read a string from the user input and store it in the array n

	// Check if any two consecutive characters in the string n are the same
	if (n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3]) {
		fmt.Println("Yes")  // Print "Yes" if the condition is true
	} else {
		fmt.Println("No")  // Print "No" if the condition is false
	}
}

