package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read an integer n
	a := make([]int, n) // Create a slice of integers with length n
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read n integers into the slice a
	}
	sort.Ints(a) // Sort the slice a
	for i := 0; i < n-1; i++ { // Iterate through the sorted slice to check for duplicates
		if a[i] == a[i+1] {
			fmt.Println("NO") // If duplicates are found, print "NO" and exit
			return
		}
	}
	fmt.Println("YES") // If no duplicates are found, print "YES"
}

// <END-OF-CODE>
