
package main

import "fmt"

func main() {
	// Initialize an array of size 3 with type int
	var a [3]int

	// Read three integers from the standard input and store them in the array
	fmt.Scan(&a[0], &a[1], &a[2])

	// Initialize two variables with zero value
	var five, seven int

	// Iterate through the array using a for loop
	for i := 0; i < 3; i++ {
		// Check if the current element of the array is equal to 5
		if a[i] == 5 {
			// Increment the variable five by 1
			five++
		}
		// Check if the current element of the array is equal to 7
		if a[i] == 7 {
			// Increment the variable seven by 1
			seven++
		}
	}

	// Check if the number of occurrences of 5 is equal to 2 and the number of occurrences of 7 is equal to 1
	if five == 2 && seven == 1 {
		// Print the string "YES" if the condition is true
		fmt.Println("YES")
	} else {
		// Print the string "NO" if the condition is false
		fmt.Println("NO")
	}

}

