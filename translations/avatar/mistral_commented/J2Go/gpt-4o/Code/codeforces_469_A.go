package main

import (
	"fmt"
)

func main() {
	var n, levels int
	fmt.Scan(&n)      // Reading the first integer input 'n'
	fmt.Scan(&levels) // Reading the second integer input 'levels'

	sum := 0
	sum2 := 0
	sum3 := 0
	arr := make([]int, levels) // Creating an integer slice 'arr' of size 'levels'
	count := 0

	for i := 0; i < levels; i++ { // Loop to read 'levels' number of integers and store them in 'arr'
		fmt.Scan(&arr[i])
	}

	var level2 int
	fmt.Scan(&level2) // Reading the third integer input 'level2'
	level3 := levels + level2
	arr2 := make([]int, level3) // Creating an integer slice 'arr2' of size 'level3'

	for i := 0; i < len(arr); i++ { // Loop to copy elements of 'arr' to 'arr2'
		arr2[i] = arr[i]
	}

	for i := len(arr); i < level3; i++ { // Loop to read 'level2' number of integers and store them in 'arr2'
		fmt.Scan(&arr2[i])
	}

	arr3 := make([]int, n) // Creating an integer slice 'arr3' of size 'n'
	for i := 0; i < n; i++ { // Loop to initialize 'arr3' with numbers from 1 to 'n'
		arr3[i] = i + 1
	}

	for i := 0; i < n; i++ { // Outer loop to compare each element of 'arr3' with 'arr2'
		for x := 0; x < len(arr2); x++ { // Inner loop to find a match between 'arr3[i]' and 'arr2[x]'
			if arr3[i] == arr2[x] { // If a match is found
				count++ // Increment the count variable
				break   // Exit the inner loop
			}
		}
	}

	if count == n { // If all elements of 'arr3' are present in 'arr2'
		fmt.Println("I become the guy.") // Print the message
	} else { // Otherwise
		fmt.Println("Oh, my keyboard!") // Print the error message
	}
}

// <END-OF-CODE>
