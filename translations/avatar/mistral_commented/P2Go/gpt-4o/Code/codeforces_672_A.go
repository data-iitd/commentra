package main

import (
	"fmt"
)

func main() {
	// Initialize an empty slice 'li' to store the digits
	var li []int

	// Iterate through the range from 1 to 370
	for i := 1; i <= 370; i++ {
		// Initialize a temporary slice 'temp' to store digits
		var temp []int

		// Assign current number 'i' to variables p and q
		p, q := i, i

		// Initialize a counter 'count' to keep track of number of digits
		count := 0

		// While p is not zero, divide it by 10 and increment the counter
		for p != 0 {
			p /= 10
			count++
		}

		// Based on the number of digits, append the number or its digits to 'li'
		if count == 1 {
			// If the number has only one digit, directly append it to 'li'
			li = append(li, i)

		} else if count == 2 || count == 3 {
			// If the number has two or three digits, extract its digits
			for q != 0 {
				x := q % 10 // Get the last digit
				q /= 10     // Move to the previous digit
				temp = append(temp, x)
			}
			// Append the reversed list to 'li'
			for j := len(temp) - 1; j >= 0; j-- {
				li = append(li, temp[j])
			}
		}
	}

	// Remove the first two elements from 'li' as they are not required
	li = li[2:]

	// Take an input 'n' from the user
	var n int
	fmt.Print("Enter a number: ")
	fmt.Scan(&n)

	// Print the required digit or digits from 'li' based on the user input
	fmt.Println(li[n-1])
}

// <END-OF-CODE>
