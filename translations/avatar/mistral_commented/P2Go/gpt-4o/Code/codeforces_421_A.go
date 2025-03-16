package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	// Reading the first list
	listaInput := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&listaInput[i])
	}

	// Reading the second list
	listbInput := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&listbInput[i])
	}

	// Creating a map to check presence in lista
	listaMap := make(map[int]bool)
	for _, value := range listaInput {
		listaMap[value] = true
	}

	// Iterating through the range of n
	for k := 0; k < n; k++ {
		if listaMap[k+1] {
			// Printing 1 if k+1 is present in the lista list
			fmt.Print(1, " ")
		} else {
			// Printing 2 if k+1 is not present in the lista list
			fmt.Print(2, " ")
		}
	}
	fmt.Println() // To ensure the output ends with a newline
}

// <END-OF-CODE>
