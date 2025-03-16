
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function declaration for linear search
func linersearch(a []int, n int, key int) bool {
	i := 0
	// Adding the key to the end of the array for the case when the key is already present at the beginning
	a[n] = key
	// Linear search algorithm to find the index of the key in the array
	for a[i]!= key {
		i++
	}
	// Returning true if the key is found, and false otherwise
	return i!= n
}

func main() {
	var n, q, t int
	var count int = 0
	var s []int
	// Reading the size of the array from user input
	fmt.Scan(&n)
	// Reading array elements into the array s
	s = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}
	// Reading the number of queries from user input
	fmt.Scan(&q)
	// Looping through each query
	for i := 0; i < q; i++ {
		// Reading a query element from user input
		fmt.Scan(&t)
		// Calling the linear search function to check if the query element is present in the array
		if linersearch(s, n, t) {
			count++
		}
	}
	// Printing the final count of query elements present in the array
	fmt.Println(count)
}

// Translate the above Go code to Python and end with comment "