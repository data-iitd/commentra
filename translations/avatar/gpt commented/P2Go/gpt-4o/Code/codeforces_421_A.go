package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	// Read the first list of integers
	var lista []int
	var input string
	fmt.Scan(&input)
	for _, val := range strings.Split(input, " ") {
		var num int
		fmt.Sscan(val, &num)
		lista = append(lista, num)
	}

	// Read the second list of integers
	var listb []int
	fmt.Scan(&input)
	for _, val := range strings.Split(input, " ") {
		var num int
		fmt.Sscan(val, &num)
		listb = append(listb, num)
	}

	// Iterate through the range of n (from 0 to n-1)
	for k := 0; k < n; k++ {
		// Check if the current index + 1 is present in lista
		found := false
		for _, v := range lista {
			if v == k+1 {
				found = true
				break
			}
		}
		// If present, print 1 followed by a space
		if found {
			fmt.Print(1, " ")
		} else {
			// If not present, print 2 followed by a space
			fmt.Print(2, " ")
		}
	}
	fmt.Println() // To ensure the output ends with a newline
}

// <END-OF-CODE>
