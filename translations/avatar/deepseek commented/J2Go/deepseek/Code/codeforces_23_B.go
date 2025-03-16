package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t) // Reading the number of test cases
	for i := 0; i < t; i++ { // Looping through each test case
		var n int
		fmt.Scan(&n) // Reading the value of n for each test case
		fmt.Println(maxLeft(n)) // Calling the maxLeft method and printing the result
	}
}

func maxLeft(n int) int { // Defining the maxLeft method
	if n > 2 {
		return n - 2
	}
	return 0
}

