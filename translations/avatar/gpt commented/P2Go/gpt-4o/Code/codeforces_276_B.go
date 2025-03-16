package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read input and convert it to a slice of characters
	var input string
	fmt.Scanln(&input)
	s := strings.Split(input, "")

	// Initialize a flag variable and a map to count occurrences of each character
	x := true
	dt := make(map[string]int)

	// Count the occurrences of each character in the input slice
	for _, i := range s {
		dt[i]++
	}

	// Initialize a counter for odd occurrences and a flag variable
	cnt := 0
	x = true

	// Check the counts of each character to determine the number of odd occurrences
	for _, value := range dt {
		if value%2 != 0 {
			if cnt < 1 {
				cnt++ // Count the first odd occurrence
			} else {
				x = false // More than one odd occurrence found, set flag to false
				break
			}
		}
	}

	// Determine the output based on the number of odd occurrences and the length of the input
	if x {
		fmt.Println("First") // If there are no more than one odd occurrences, print "First"
	} else if !x && len(s)%2 == 0 {
		fmt.Println("Second") // If there are more than one odd occurrences and the length is even, print "Second"
	} else if !x && len(s)%2 != 0 {
		fmt.Println("First") // If there are more than one odd occurrences and the length is odd, print "First"
	}
}

// <END-OF-CODE>
