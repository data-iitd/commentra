package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	var lista, listb []int
	var input string

	// Read the first list
	fmt.Scan(&input)
	for _, x := range strings.Split(input, " ") {
		var num int
		fmt.Sscan(x, &num)
		lista = append(lista, num)
	}

	// Read the second list
	fmt.Scan(&input)
	for _, x := range strings.Split(input, " ") {
		var num int
		fmt.Sscan(x, &num)
		listb = append(listb, num)
	}

	for k := 0; k < n; k++ {
		if contains(lista, k+1) {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
}

// Helper function to check if a slice contains a value
func contains(slice []int, value int) bool {
	for _, v := range slice {
		if v == value {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
