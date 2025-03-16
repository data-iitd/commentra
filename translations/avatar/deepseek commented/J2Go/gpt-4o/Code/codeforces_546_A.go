package main

import (
	"fmt"
)

func main() {
	var pandu, vundu, urdu, c int64 // Declare four int64 variables to store user input and a variable for accumulation

	fmt.Scan(&pandu) // Read the first int64 input from the user
	fmt.Scan(&vundu) // Read the second int64 input from the user
	fmt.Scan(&urdu)  // Read the third int64 input from the user

	// The for loop iterates from 1 to urdu (inclusive)
	// In each iteration, it calculates the product of i and pandu and adds it to the variable c
	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
	}

	// The if-else statement checks if the value of c is less than vundu
	// If it is, the program prints "0". Otherwise, it prints the difference between c and vundu
	if c < vundu {
		fmt.Print("0")
	} else {
		fmt.Print(c - vundu)
	}
}

// <END-OF-CODE>
