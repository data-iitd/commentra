package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the size of the array
	a := make([]int, n) // Initialize the array of size n
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Populate the array with n integers
	}
	sort.Ints(a) // Sort the array
	for i := 0; i < len(a)-1; i++ {
		if a[i+1] < a[i]*2 && a[i] != a[i+1] { // Check if any element is less than twice the previous element
			fmt.Println("YES")
			return // Exit the program after printing "YES"
		}
	}
	fmt.Println("NO") // Print "NO" if no such condition is found
}

// <END-OF-CODE>
