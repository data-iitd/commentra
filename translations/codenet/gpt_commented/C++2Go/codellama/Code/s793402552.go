package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	// Read two integers a and b from input
	var a, b int
	fmt.Scan(&a, &b)

	// Convert b to string to determine its length
	bstr := strconv.Itoa(b)

	// Calculate the number formed by concatenating a and b
	num := a*int(math.Pow10(len(bstr))) + b

	// Initialize a variable to find the square root of num
	var i int
	// Loop to check if there exists an integer i such that i*i equals num
	for i = 1; i <= 100100; i++ {
		if i*i == num {
			break
		}
	}

	// Check if a valid integer i was found within the range
	if i > 100100 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

