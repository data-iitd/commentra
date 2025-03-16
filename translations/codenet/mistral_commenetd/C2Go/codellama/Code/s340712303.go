
package main

import "fmt"

func main() {
	// Initialize variables
	var a, num2, ans, sum int = 0, 0, 0, 0
	var i, j int = 0, 0
	var math [2001]int = [2001]int{1}

	// Read the number of integers to be input
	fmt.Print("Enter the number of integers to be input:\n")
	fmt.Scan(&num1)

	// Read each integer and calculate its sum
	for i = 0; i < num1; i++ {
		fmt.Print("Enter an integer:\n")
		fmt.Scan(&a)

		// Add the current integer to the sum
		sum += a

		// Mark all the previous numbers as visited
		for j = sum - a; j >= 0; j-- {
			if math[j] == 1 {
				math[j+a] = 1
			}
		}
	}

	// Read the number of integers to be checked
	fmt.Print("Enter the number of integers to be checked:\n")
	fmt.Scan(&num2)

	// Check each integer and print the result
	for i = 0; i < num2; i++ {
		fmt.Print("Enter an integer to check:\n")
		fmt.Scan(&ans)

		// Check if the current integer is marked as visited
		if math[ans] == 1 {
			fmt.Print("yes\n")
		} else {
			fmt.Print("no\n")
		}
	}
}

