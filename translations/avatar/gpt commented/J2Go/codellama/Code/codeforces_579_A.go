package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the user
	var n int
	fmt.Scan(&n)

	// Initializing an empty string to store the binary representation
	var s string

	// Converting the integer n to its binary representation
	for n > 0 {
		x := n % 2 // Getting the least significant bit (0 or 1)
		n /= 2     // Dividing n by 2 to process the next bit
		s += strconv.Itoa(x) // Appending the bit to the binary string
	}

	// Initializing a counter to count the number of '1's in the binary representation
	var ans int

	// Iterating through the binary string to count '1's
	for i := 0; i < len(s); i++ {
		if s[i] == '1' { // Checking if the current character is '1'
			ans++ // Incrementing the count of '1's
		}
	}

	// Printing the total count of '1's in the binary representation
	fmt.Println(ans)
}

