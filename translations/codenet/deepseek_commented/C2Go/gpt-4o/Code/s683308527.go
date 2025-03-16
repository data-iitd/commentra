package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int // Declare an integer to store the number of lines
	fmt.Scanf("%d\n", &n) // Read the number of lines and consume the newline character

	for n > 0 { // Loop through each line
		n-- // Decrement the line counter
		var s string
		fmt.Scanln(&s) // Read the input line

		// Replace "Hoshino" with "Hoshina"
		s = strings.Replace(s, "Hoshino", "Hoshina", -1)

		fmt.Println(s) // Print the modified line
	}
}

// <END-OF-CODE>
