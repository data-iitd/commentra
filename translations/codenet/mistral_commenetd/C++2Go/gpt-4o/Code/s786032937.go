package main

import (
	"fmt"
)

func main() {
	// Declare an integer variable 'n' and read its value from the standard input
	var n int
	fmt.Scan(&n)

	// Output the result, which is calculated as (n - 2) * 180
	fmt.Println((n - 2) * 180)

	// Indicate successful termination of the program by returning 0
	// In Go, the program ends successfully if it reaches the end of main
}

// <END-OF-CODE>
