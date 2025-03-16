/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
package main

import (
	"fmt"
)

func solve() {
	var n int // Declare variable for the input number
	fmt.Scan(&n) // Read the input number
	fmt.Println(n == 0) // Output the boolean negation of n
}

func main() {
	n := 1 // Initialize n with 1
	for n > 0 {
		solve() // Run the solve function in a loop with n=1
		n-- // Decrement n
	}
}
