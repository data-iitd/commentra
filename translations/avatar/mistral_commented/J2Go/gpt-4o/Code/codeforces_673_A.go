package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements

	a := make([]int, n) // Creating a slice of integers

	for i := 0; i < n; i++ { // Loop to read and add each element
		fmt.Scan(&a[i]) // Reading an integer value
	}

	var result, pos, flag int // Declaring variables

	if a[0] > 15 { // Checking if the first element is greater than 15
		result = 15 // Assigning 15 to result
	} else {
		for i := 1; i < n; i++ { // Loop to compare each element with the previous one
			if a[i]-a[i-1] > 15 { // Checking the difference
				pos = i - 1 // Assigning the index of the previous element
				flag = 1    // Setting flag to indicate the condition is true
				break       // Exiting the loop
			}
		}
		if flag == 1 { // If the flag is set
			result = a[pos] + 15 // Assigning the sum of the previous element and 15
		} else {
			result = a[n-1] + 15 // Assigning the sum of the last element and 15
		}
	}

	if result > 90 { // Checking if result is greater than 90
		result = 90 // Assigning 90 to result if true
	}

	fmt.Println(result) // Printing the result
}

// <END-OF-CODE>
