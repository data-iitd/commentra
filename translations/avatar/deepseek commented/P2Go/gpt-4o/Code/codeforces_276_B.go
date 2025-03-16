package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input) // Read input from the user
	s := strings.Split(input, "") // Convert the input string into a slice of characters
	x := true // Initialize a boolean variable to track the result
	dt := make(map[string]int) // Initialize an empty map to store character frequencies

	// Iterate over each character in the input string and update the frequency count in the map
	for _, i := range s {
		dt[i]++
	}

	cnt := 0 // Initialize a counter to keep track of characters with an odd frequency
	x = true // Reset the boolean variable to track the result

	// Iterate over the items in the map to determine if there is more than one character with an odd frequency
	for _, value := range dt {
		if value%2 != 0 {
			if cnt < 1 {
				cnt++
			} else {
				x = false
				break
			}
		}
	}

	// Determine the output based on the value of cnt and the length of the input string
	if x {
		fmt.Println("First") // Print "First" if there is at most one character with an odd frequency
	} else if !x && len(s)%2 == 0 {
		fmt.Println("Second") // Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
	} else if !x && len(s)%2 != 0 {
		fmt.Println("First") // Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
	}
}

// <END-OF-CODE>
