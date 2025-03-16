
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Read input and convert it to a list of characters
	s := make([]byte, 0)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		s = append(s, scanner.Bytes()...)
	}

	// Initialize a flag variable and a dictionary to count occurrences of each character
	x := true
	dt := make(map[byte]int)

	// Count the occurrences of each character in the input list
	for _, i := range s {
		if v, ok := dt[i]; ok {
			dt[i] = v + 1 // Increment the count if the character is already in the dictionary
		} else {
			dt[i] = 1 // Initialize the count to 1 if the character is not in the dictionary
		}
	}

	// Initialize a counter for odd occurrences and a flag variable
	cnt := 0
	x = true

	// Check the counts of each character to determine the number of odd occurrences
	for key, value := range dt {
		if value%2!= 0 && cnt < 1 {
			cnt += 1 // Count the first odd occurrence
		} else if value%2!= 0 && cnt >= 1 {
			x = false // More than one odd occurrence found, set flag to False
			break
		}
	}

	// Determine the output based on the number of odd occurrences and the length of the input
	if x {
		fmt.Println("First") // If there are no more than one odd occurrences, print "First"
	} else if!x && len(s)%2 == 0 {
		fmt.Println("Second") // If there are more than one odd occurrences and the length is even, print "Second"
	} else if!x && len(s)%2!= 0 {
		fmt.Println("First") // If there are more than one odd occurrences and the length is odd, print "First"
	}
}
