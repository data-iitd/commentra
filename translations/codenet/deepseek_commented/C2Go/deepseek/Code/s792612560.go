package main

import (
	"fmt"
)

func main() {
	var n int // Step 3: Declare an integer variable n
	var m uint64 // Step 3: Declare an unsigned long long integer variable m
	fmt.Scan(&n) // Step 4: Read an integer input from the user and store it in n
	m = uint64(n) // Step 5: Copy the value of n to m
	n-- // Step 6: Decrement the value of n by 1
	for ; n > 1; n-- { // Step 7: Start a for loop that runs while n is greater than 1
		m *= uint64(n) // Inside the loop, multiply m by n and decrement n by 1
	}
	fmt.Println(m) // Step 8: Print the value of m, which represents the factorial of the input number
}

