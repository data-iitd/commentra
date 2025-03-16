package main

import "fmt"

func main() {
	// Declare an array 'a' of size 3 to hold integer inputs
	var a [3]int

	// Read three integers from standard input into the array 'a'
	fmt.Scan(&a[0], &a[1], &a[2])

	// Initialize counters for occurrences of the numbers 5 and 7
	five := 0
	seven := 0

	// Iterate over the array to count occurrences of 5 and 7
	for i := 0; i < 3; i++ {
		// Increment the 'five' counter if the current element is 5
		if a[i] == 5 {
			five++
		}
		// Increment the 'seven' counter if the current element is 7
		if a[i] == 7 {
			seven++
		}
	}

	// Check if there are exactly two occurrences of 5 and one occurrence of 7
	if five == 2 && seven == 1 {
		// Print "YES" if the condition is met
		fmt.Println("YES")
	} else {
		// Print "NO" if the condition is not met
		fmt.Println("NO")
	}
}
