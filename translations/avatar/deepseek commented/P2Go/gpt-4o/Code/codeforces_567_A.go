package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Taking an integer input from the user

	var input string
	fmt.Scan(&input) // Reading the input string
	listaStr := strings.Split(input, " ") // Splitting the input string into a slice of strings
	lista := make([]int, n)

	// Converting the input strings into a slice of integers
	for i, v := range listaStr {
		num, _ := strconv.Atoi(v)
		lista[i] = num
	}

	// Iterating through the slice of integers
	for i := 0; i < len(lista); i++ {
		// For the first element in the slice
		if i == 0 {
			fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[len(lista)-1]-lista[i]) // Printing the differences
			continue
		}
		// For the last element in the slice
		if i == len(lista)-1 {
			fmt.Printf("%d %d\n", lista[len(lista)-1]-lista[len(lista)-2], lista[len(lista)-1]-lista[0]) // Printing the differences
			continue
		}
		// For other elements in the slice
		if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
			fmt.Print(lista[i+1]-lista[i], " ") // Printing the difference between the next and current integer
		} else {
			fmt.Print(lista[i]-lista[i-1], " ") // Printing the difference between the current and previous integer
		}
		// Printing the difference between the last and current integer or the first and current integer
		if lista[len(lista)-1]-lista[i] > lista[i]-lista[0] {
			fmt.Println(lista[len(lista)-1] - lista[i]) // Printing the difference between the last and current integer
		} else {
			fmt.Println(lista[i] - lista[0]) // Printing the difference between the first and current integer
		}
	}
}

// <END-OF-CODE>
