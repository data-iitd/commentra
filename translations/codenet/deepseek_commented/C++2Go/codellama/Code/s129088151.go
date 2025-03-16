package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int // Declare an integer variable to store the number of operations
	var str, com string // Declare string variables to store commands and strings
	T := make(map[string]bool) // Declare a map to store the presence of strings

	fmt.Scan(&n) // Read the number of operations from the user
	for i := 0; i < n; i++ { // Loop through each operation
		fmt.Scan(&com, &str) // Read the command and the string
		if com[0] == 'i' { // If the command is 'i', insert the string into the map
			T[str] = true
		} else { // If the command is not 'i'
			if T[str] { // Check if the string is present in the map and print 'yes'
				fmt.Println("yes")
			} else { // If the string is not present, print 'no'
				fmt.Println("no")
			}
		}
	}
}

