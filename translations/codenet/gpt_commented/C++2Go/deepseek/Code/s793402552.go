package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	// Convert b to string to determine its length
	bStr := strconv.Itoa(b)
	
	// Calculate the number formed by concatenating a and b
	num := a * int(math.Pow(10, float64(len(bStr)))) + b

	// Initialize a variable to find the square root of num
	var i int
	// Loop to check if there exists an integer i such that i*i equals num
	for i = 1; i <= 100100; i++ {
		if i * i == num {
			break // If found, exit the loop
		}
	}

	// Check if a valid integer i was found within the range
	if i > 100100 {
		fmt.Println("No") // If no such i exists, print "No"
	} else {
		fmt.Println("Yes") // If such i exists, print "Yes"
	}
}

