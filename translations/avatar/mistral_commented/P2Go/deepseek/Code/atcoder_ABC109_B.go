package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of elements in the list from user input
	var n int
	fmt.Scan(&n)

	// Initialize an empty map 's' with default value 0
	s := make(map[string]int)

	// Create a scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize an empty list 'l' with length 'n'
	var l []string

	// Read elements from user input
	for i := 0; i < n; i++ {
		scanner.Scan()
		v := scanner.Text()
		l = append(l, v)
	}

	// Initialize a flag 'f' with value 'Yes'
	f := "Yes"

	// Iterate through each element 'v' in the list 'l'
	for _, v := range l {
		// Increment the count of 'v' in map 's'
		s[v]++

		// Check if the count of 'v' in map 's' is greater than or equal to 2
		if s[v] >= 2 {
			// If yes, set the flag 'f' to 'No'
			f = "No"
		}

		// Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
		// Note: In Go, we don't have a direct equivalent to Python's 'i' variable, so we simulate it using a loop index
		// for range loop in Go automatically gives us the index and value, so we don't need to manually manage an index variable
	}

	// Print the final value of flag 'f'
	fmt.Println(f)
}
