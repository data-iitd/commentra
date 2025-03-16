package main

import (
	"fmt"
)

const N = 2000

func main() {
	var num1 int
	var math [N+1]int

	// Initialize variables
	var a, num2, ans, sum int

	// Initialize math array with first element as 1
	math[0] = 1

	// Read the number of integers to be input
	fmt.Println("Enter the number of integers to be input:")
	fmt.Scanln(&num1)

	// Read each integer and calculate its sum
	for i := 0; i < num1; i++ {
		fmt.Println("Enter an integer:")
		fmt.Scanln(&a)

		// Add the current integer to the sum
		sum += a

		// Mark all the previous numbers as visited
		for j := sum - a; j >= 0; j-- {
			if math[j] == 1 {
				math[j+a] = 1
			}
		}
	}

	// Read the number of integers to be checked
	fmt.Println("Enter the number of integers to be checked:")
	fmt.Scanln(&num2)

	// Check each integer and print the result
	for i := 0; i < num2; i++ {
		fmt.Println("Enter an integer to check:")
		fmt.Scanln(&ans)

		// Check if the current integer is marked as visited
		if math[ans] == 1 {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

