package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Comment 3: Reads the size of the array p from standard input

	p := make([]int, n) // Comment 4: Initializes the slice p with n integers
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i]) // Populates the slice p with n integers from standard input
	}

	ans := 0 // Comment 5: Initializes the variable ans to 0

	for i := 0; i < n-2; i++ { // Comment 6: Loops through the slice p
		if p[i] > p[i+1] && p[i+1] > p[i+2] {
			ans++ // Comment 7: Checks for a peak and increments ans
		}
		if p[i] < p[i+1] && p[i+1] < p[i+2] {
			ans++ // Comment 8: Checks for a valley and increments ans
		}
	}

	fmt.Println(ans) // Comment 9: Prints the final value of ans to standard output
} // Comment 10: Ends the program
