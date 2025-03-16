package main

import (
	"fmt"
	"strings"
)

func main() {
	// Initialize an empty map 'dt' to store the count of each unique element
	dt := make(map[rune]int)

	// Read input and convert it to a slice of runes
	var input string
	fmt.Scan(&input)
	s := []rune(input)

	// Iterate through each element 'i' in the slice 's'
	for _, i := range s {
		// Increment the count of the element in the map
		dt[i]++
	}

	// Initialize a counter 'cnt' to 0 and a boolean variable 'x' to true
	cnt := 0
	x := true

	// Iterate through each key-value pair in the map 'dt'
	for _, value := range dt {
		// If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
		if value%2 != 0 && cnt < 1 {
			cnt++
		} else if value%2 != 0 && cnt >= 1 {
			// If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to false and break the loop
			x = false
			break
		}
	}

	// After the loop, check the value of 'x'
	if x {
		// If it is true, print "First"
		fmt.Println("First")
	} else if !x && len(s)%2 == 0 {
		// If it is false and the length of the slice 's' is even, print "Second"
		fmt.Println("Second")
	} else if !x && len(s)%2 != 0 {
		// If it is false and the length of the slice 's' is odd, print "First"
		fmt.Println("First")
	}
}

// <END-OF-CODE>
