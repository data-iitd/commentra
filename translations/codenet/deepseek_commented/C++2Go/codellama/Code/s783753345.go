package main

import (
	"fmt"
)

func main() {
	// Declare variables to store integers and a character
	var a, b int
	var S byte

	// Infinite loop to continuously take input and perform operations
	for {
		// Take input in the format a S b
		fmt.Scan(&a, &S, &b)

		// Perform operations based on the value of S
		if S == '+' {
			fmt.Println(a + b)
		} else if S == '-' {
			fmt.Println(a - b)
		} else if S == '*' {
			fmt.Println(a * b)
		} else if S == '/' {
			fmt.Println(a / b)
		} else {
			break
		}
	}
}

