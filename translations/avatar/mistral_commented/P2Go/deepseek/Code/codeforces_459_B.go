package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in the list

	var l1 []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x) // Read the list elements and add them to the slice
		l1 = append(l1, x)
	}

	sort.Ints(l1) // Sort the slice in ascending order

	a := l1[len(l1)-1] // Assign the last element of the sorted slice to the variable a
	b := l1[0]        // Assign the first element of the sorted slice to the variable b

	if a == b { // Check if the first and the last elements are equal
		fmt.Println(a-b, (n*(n-1))/2) // If so, calculate and print the result
	} else {
		var ac, bc int
		for _, v := range l1 {
			if v == a {
				ac++
			}
			if v == b {
				bc++
			}
		}
		fmt.Println(a-b, ac*bc) // Print the result
	}
}

