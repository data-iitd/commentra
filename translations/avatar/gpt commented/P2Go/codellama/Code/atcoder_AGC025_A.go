package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Read input from the user
	var n string
	fmt.Scan(&n)

	// Define a list of string representations of powers of ten
	a := []string{"10", "100", "1000", "10000", "100000"}

	// Convert the input string into a list of integers and calculate the sum
	new := 0
	for _, v := range n {
		i, _ := strconv.Atoi(string(v))
		new += i
	}

	// Check if the input is one of the predefined values in the list 'a'
	for _, v := range a {
		if v == n {
			// If the input matches one of the predefined values, print 10
			fmt.Println(10)
			return
		}
	}

	// If the input does not match, print the calculated sum
	fmt.Println(new)
}

