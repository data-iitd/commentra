package main

import (
	"fmt"
)

func main() {
	var n int

	// Reading the first number from the user input
	fmt.Scan(&n)

	fmt.Print(n, " ")

	m := n

	// Finding the factors of the number 'n' using a for loop
	for i := n - 1; i > 0; i-- {
		if m%i == 0 {
			fmt.Print(i, " ")
			m = i
		}
	}
}

