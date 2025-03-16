package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize an empty slice 's' to store input elements
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadSlice('\n')

	// Initialize an empty map 'dt' to store the count of each unique element
	dt := make(map[byte]int)

	// Set a boolean variable 'x' to true to indicate whether there is an odd count element in the list
	x := true

	// Iterate through each element 'i' in the slice 's'
	for _, i := range s {
		// Check if the element 'i' already exists as a key in the map 'dt'
		if _, exists := dt[byte(i)]; exists {
			// If it does, increment its value by 1
			dt[byte(i)] += 1
		} else {
			// If not, add it as a new key with a value of 1
			dt[byte(i)] = 1
		}
	}

	// Initialize a counter 'cnt' to 0 and set 'x' to true
	cnt := 0
	x = true

	// Iterate through each key-value pair ('key', 'value') in the map 'dt'
	for _, value := range dt {
		// If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
		if value%2 != 0 && cnt < 1 {
			cnt += 1
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

