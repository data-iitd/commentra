package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Print("Enter an integer: ") // Read an integer from the user
	fmt.Scan(&n)

	for n%2 == 0 { // While n is even
		n /= 2 // Divide n by 2 to remove the last even factor
	}

	if n == 1 { // If n is now 1
		fmt.Println("YES") // Print 'YES'
	} else { // Otherwise
		fmt.Println("NO") // Print 'NO'
	}
}

// <END-OF-CODE>
