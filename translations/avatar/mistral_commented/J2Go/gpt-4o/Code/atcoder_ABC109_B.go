package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Reading the number of strings from the input

	mapStrings := make(map[int]string) // Creating an empty map to store strings

	for i := 0; i < N; i++ { // Loop to read strings from the input and store them in the map
		var str string
		fmt.Scan(&str)
		mapStrings[i] = str
	}

	ans := true // Initializing a boolean variable to store the result of the check
	past := make(map[int]string) // Creating an empty map to store the previous strings
	next := "" // Initializing a string variable to store the next character of the current string

	for i := 0; i < N; i++ { // Loop to check for the condition
		if _, exists := past[i]; exists { // Checking if the current string is already in the map
			ans = false
			break
		}
		past[i] = mapStrings[i] // Storing the current string in the map

		if i != 0 { // Checking if it's not the first iteration of the loop
			if next != string(mapStrings[i][0]) { // Checking if the current string starts with the same character as the previous string
				ans = false
				break
			}
		}
		next = string(mapStrings[i][len(mapStrings[i])-1]) // Storing the last character of the current string in the next variable
	}

	if ans { // Printing "Yes" if the condition is satisfied
		fmt.Println("Yes")
	} else { // Printing "No" if the condition is not satisfied
		fmt.Println("No")
	}
}

// <END-OF-CODE>
