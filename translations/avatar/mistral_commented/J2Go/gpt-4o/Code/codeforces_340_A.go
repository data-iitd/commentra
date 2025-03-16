package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int64 // Reading the first four integer values from user input
	fmt.Scan(&x, &y, &a, &b)

	var j int64 = 2
	var c int64 = 0
	ans := true // Initializing a boolean variable to keep track of the result

	c = max(x, y) // Finding the maximum value between x and y

	if c > b { // Checking if the maximum value is greater than b
		fmt.Println("0") // If true, printing 0 and setting ans to false
		ans = false
	}

	for c%min(x, y) != 0 && ans { // Loop to find the greatest common divisor (GCD)
		if x > y { // If x is greater than y
			c = x * j // Multiplying x by j and updating c
			j++       // Incrementing j
		} else {
			c = y * j // Multiplying y by j and updating c
			j++       // Incrementing j
		}

		if c > b { // Checking if the current value of c is greater than b
			fmt.Println("0") // If true, printing 0 and setting ans to false
			ans = false
			break // Exiting the loop
		}
	}

	if ans { // If the GCD has been found
		count := int64(0) // Initializing a counter variable
		i := a            // Starting the loop from a

		for i <= b { // Loop to find the number of times c divides i
			if i%c == 0 {
				break // If i is divisible by c, breaking the loop
			}
			i++
		}

		if i != b+1 { // Checking if the last number in the range is divisible by c
			fmt.Println((b - i) / c + 1) // Printing the result
		} else {
			fmt.Println("0") // If the last number is not divisible by c, printing 0
		}
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
