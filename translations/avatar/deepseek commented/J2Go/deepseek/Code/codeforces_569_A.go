package main

import (
	"fmt"
)

func main() {
	// Read the values of T, S, and q from the user input
	var T, S, q int
	fmt.Scan(&T, &S, &q)
	
	// Initialize the variable `previous` with the value of S
	previous := S
	
	// Initialize the variable `answer` with the value 0
	answer := 0
	
	// Enter a while loop that continues until `previous` is less than T
	for previous < T {
		// Inside the loop, multiply `previous` by q and increment the `answer` by 1
		previous *= q
		answer++
	}
	
	// After the loop, print the value of `answer`
	fmt.Println(answer)
}
