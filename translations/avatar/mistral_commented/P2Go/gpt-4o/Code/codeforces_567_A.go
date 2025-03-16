package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take an integer input from the user
	var n int
	fmt.Scan(&n)

	// Create a slice to store the input integers
	lista := make([]int, 0)

	// Populate the slice 'lista' with integers input by the user, separated by spaces
	var input string
	fmt.Scan(&input)
	for _, str := range strings.Split(input, " ") {
		if num, err := strconv.Atoi(str); err == nil {
			lista = append(lista, num)
		}
	}

	// Iterate through each index 'i' in the slice 'lista'
	for i := 0; i < len(lista); i++ {
		// If 'i' is the first index
		if i == 0 {
			// Print the difference between the second and first elements and the difference between the last and first elements
			fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[len(lista)-1]-lista[i])
			continue
		}

		// If 'i' is the last index
		if i == len(lista)-1 {
			// Print the difference between the last and second last element and the difference between the last and first element
			fmt.Printf("%d %d\n", lista[len(lista)-1]-lista[len(lista)-2], lista[len(lista)-1]-lista[0])
			continue
		}

		// If the difference between the current index and the previous index is greater than the difference between the next index and the current index
		if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
			// Print the difference between the next index and the current index
			fmt.Print(lista[i+1] - lista[i], " ")
		} else {
			// Print the difference between the current index and the previous index and the difference between the current index and the first index
			fmt.Print(lista[i]-lista[i-1], " ")
			if lista[len(lista)-1]-lista[i] > lista[i]-lista[0] {
				fmt.Println(lista[len(lista)-1] - lista[i])
			} else {
				fmt.Println(lista[i] - lista[0])
			}
		}
	}
}

// <END-OF-CODE>
