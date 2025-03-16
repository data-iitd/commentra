package main

import (
	"fmt"
)

func main() {
	var tc, n, m int
	fmt.Scan(&tc, &n, &m) // Read three integers from standard input

	if n > m {
		n, m = m, n // Swap n and m if n is greater than m
	}

	fl := 0 // Declare a flag variable

	for i := 1; i <= m; i++ { // Iterate from 1 to m
		if i*tc >= n && i*tc <= m { // Check if the product of i and tc is between n and m
			fmt.Println("OK") // Print "OK" if the condition is met
			fl = 1 // Set the flag to true
			break // Exit the loop
		}
	}

	if fl == 0 {
		fmt.Println("NG") // Print "NG" if the flag is still false after the loop
	}
}

// <END-OF-CODE>
