package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s) // Reading a string input from user

	targ := []rune(s) // Converting the string input to a rune slice

	mapFreq := make(map[rune]int) // Creating an empty map to store character and their frequency

	for _, currentChar := range targ { // Iterating through each character in the rune slice
		mapFreq[currentChar]++ // Incrementing the frequency of the current character in the map
	}

	ok := true // Initializing a boolean variable to check if all characters have frequency 2 or not

	for _, value := range mapFreq { // Iterating through each value in the map
		if value != 2 { // Checking if the frequency of the current character is not 2
			ok = false // Setting the boolean variable to false if any character has frequency other than 2
			break // Exiting the loop if any character has frequency other than 2
		}
	}

	if ok && len(mapFreq) == 2 { // Checking if all characters have frequency 2 and the size of the map is 2
		fmt.Println("Yes") // Printing "Yes" if both conditions are true
	} else {
		fmt.Println("No") // Printing "No" if any character has frequency other than 2 or the size of the map is not 2
	}
}

// <END-OF-CODE>
