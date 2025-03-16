package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of integers
	a := make([]int, 0, n) // Create a slice to store integers

	if n == 1 { // Check if there is only one integer
		var singleInt int
		fmt.Scan(&singleInt) // Read the single integer
		fmt.Println(singleInt) // Print the single integer
		return // Exit the program
	}

	for i := 0; i < n; i++ { // Read n integers and add them to the slice
		var num int
		fmt.Scan(&num)
		a = append(a, num)
	}

	sort.Ints(a) // Sort the slice

	if a[len(a)-1] == 0 { // Check if the largest element is 0
		fmt.Println(0) // Print 0 and exit the program
		return
	}

	var ans int // Initialize the result variable

	for {
		if len(a) == 1 { // Check if there is only one element left
			ans = a[0] // Assign the single element to ans
			break // Exit the loop
		}
		a = func(a []int) []int { // Call the func method to update the slice
			min := 0 // Initialize the minimum variable
			newA := make([]int, 0) // Create a new slice to store updated values

			for _, value := range a { // Iterate through the slice
				if value == 0 { // Skip elements that are zero
					continue
				} else { // Process non-zero elements
					if min != 0 { // Check if min is not zero
						newValue := value % min // Perform modulo operation
						if newValue == 1 { // Check if the result is 1
							fmt.Println(1) // Print 1 and exit the program
							return nil // Exit the program
						}
						newA = append(newA, newValue) // Add the new value to the new slice
					} else { // Find the minimum non-zero element
						min = value
						newA = append(newA, value) // Add the value to the new slice
					}
				}
			}

			sort.Ints(newA) // Sort the new slice
			return newA // Return the updated slice
		}(a) // Call the anonymous function
	}

	fmt.Println(ans) // Print the final result
}

// <END-OF-CODE>
