
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize an empty slice's' to store input elements
	s := make([]byte, 0)

	// Initialize an empty map 'dt' to store the count of each unique element
	dt := make(map[byte]int)

	// Set a boolean variable 'x' to true to indicate whether there is an odd count element in the slice
	x := true

	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Iterate through each line of input
	for scanner.Scan() {
		// Convert the line of input to a byte slice and append it to the slice's'
		s = append(s, scanner.Bytes()...)
	}

	// Sort the slice's' in ascending order
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})

	// Iterate through each element 'i' in the slice's'
	for i := 0; i < len(s); i++ {
		// Check if the element 'i' already exists as a key in the map 'dt'
		if _, ok := dt[s[i]]; ok {
			// If it does, increment its value by 1
			dt[s[i]]++
		} else {
			// If not, add it as a new key with a value of 1
			dt[s[i]] = 1
		}
	}

	// Initialize a counter 'cnt' to 0 and set 'x' to true
	cnt := 0
	x = true

	// Iterate through each key-value pair ('key', 'value') in the map 'dt'
	for key, value := range dt {
		// If the value is odd and 'cnt' is less than 1, increment 'cnt' by 1
		if value%2!= 0 && cnt < 1 {
			cnt++
		}
		// If the value is odd and 'cnt' is already greater than or equal to 1, set 'x' to false and break the loop
		if value%2!= 0 && cnt >= 1 {
			x = false
			break
		}
	}

	// After the loop, check the value of 'x'
	if x {
		// If it is true, print "First"
		fmt.Println("First")
	} else if!x && len(s)%2 == 0 {
		// If it is false and the length of the slice's' is even, print "Second"
		fmt.Println("Second")
	} else if!x && len(s)%2!= 0 {
		// If it is false and the length of the slice's' is odd, print "First"
		fmt.Println("First")
	}
}

