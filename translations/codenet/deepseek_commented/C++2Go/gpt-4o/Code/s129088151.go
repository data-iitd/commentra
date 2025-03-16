package main

import (
	"fmt"
)

func main() {
	var n int // Declare an integer variable to store the number of operations
	var str string // Declare a string variable to store the input string
	var com string // Declare a string variable to store the command
	T := make(map[string]bool) // Declare a map to store the presence of strings

	fmt.Scan(&n) // Read the number of operations from the user
	for i := 0; i < n; i++ { // Loop through each operation
		fmt.Scan(&com, &str) // Read the command and the string
		if com == "insert" { // If the command is 'insert', insert the string into the map
			T[str] = true
		} else { // If the command is not 'insert'
			if T[str] { // Check if the string is present in the map
				fmt.Println("yes") // Print 'yes' if present
			} else {
				fmt.Println("no") // Print 'no' if not present
			}
		}
	}
}

// <END-OF-CODE>
