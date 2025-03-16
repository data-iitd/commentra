package main

import (
	"fmt"
)

func main() {
	var a, b, c int

	// Read three integers from the standard input using fmt.Scan()
	fmt.Scan(&a, &b, &c)

	// Check if the condition 'b > a * c' is true
	if b > a * c {
		// If the condition is true, print the value of 'c'
		fmt.Println(c)
	} else {
		// If the condition is false, calculate the integer division of 'b' by 'a'
		// and print the result
		fmt.Println(b / a)
	}
}

