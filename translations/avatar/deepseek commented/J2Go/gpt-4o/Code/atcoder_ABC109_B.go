package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Step 1: Read the input value N

	mapStrings := make(map[int]string) // Step 2: Initialize a map

	for i := 0; i < N; i++ { // Step 3: Read N strings and store them in the map
		var str string
		fmt.Scan(&str)
		mapStrings[i] = str
	}

	ans := true // Step 4: Initialize a boolean variable 'ans'
	past := make(map[int]string) // Step 5: Initialize another map
	next := "" // Step 6: Initialize a variable 'next'

	for i := 0; i < N; i++ { // Step 7: Loop through the strings
		if _, exists := past[i]; exists && past[i] == mapStrings[i] { // Step 8: Check if the current string has been seen before
			ans = false
			break
		}
		past[i] = mapStrings[i] // Step 9: Store the current string in the 'past' map

		if i != 0 { // Step 10: Check if it's not the first string
			if string(mapStrings[i][0]) != next { // Check if the starting character matches
				ans = false
				break
			}
		}
		next = string(mapStrings[i][len(mapStrings[i])-1]) // Step 11: Update 'next'
	}

	if ans { // Step 12: Check the value of 'ans'
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
