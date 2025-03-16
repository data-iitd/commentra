package main

import (
	"fmt"
	"sort"
)

func main() {
	// Creating a Scanner object to read input from the console
	var n int
	fmt.Scan(&n)
	
	// Initializing an array of size n
	a := make([]int, n)
	
	// Loop to read n integers from the user and store them in the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	
	// Sorting the array in ascending order
	sort.Ints(a)
	
	// Loop to check the condition for adjacent elements in the sorted array
	for i := 0; i < len(a) - 1; i++ {
		// Checking if the next element is less than double the current element
		// and ensuring they are not equal
		if a[i + 1] < a[i] * 2 {
			// If the condition is met, print "YES" and exit the program
			fmt.Println("YES")
			return
		}
	}
	
	// If no such pair is found, print "NO"
	fmt.Println("NO")
}
