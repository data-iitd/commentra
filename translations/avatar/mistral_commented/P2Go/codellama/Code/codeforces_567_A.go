package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take an integer input from the user
	var inp int
	fmt.Scan(&inp)

	// Create an empty list to store the input integers
	var lista []int

	// Populate the list 'lista' with integers input by the user, separated by spaces
	fmt.Scan(&lista)
	lista = strings.Split(lista, " ")
	for i := range lista {
		lista[i], _ = strconv.Atoi(lista[i])
	}

	// Iterate through each index 'i' in the list 'lista'
	for i := range lista {
		// If 'i' is the first index
		if i == 0 {
			// Print the difference between the second and first elements and the difference between the last and first elements
			fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[len(lista)-1]-lista[i])
			continue
		}

		// If 'i' is the last index
		if i == len(lista)-1 {
			// Print the difference between the last and second last element and the difference between the last and first element
			fmt.Printf("%d %d\n", lista[i]-lista[i-1], lista[i]-lista[0])
			continue
		}

		// If the difference between the current index and the previous index is greater than the difference between the next index and the current index
		if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
			// Print the difference between the next index and the current index
			fmt.Printf("%d ", lista[i+1]-lista[i])
		} else {
			// Print the difference between the current index and the previous index and the difference between the current index and the first index
			fmt.Printf("%d ", lista[i]-lista[i-1])
			if lista[len(lista)-1]-lista[i] > lista[i]-lista[0] {
				fmt.Printf("%d\n", lista[len(lista)-1]-lista[i])
			} else {
				fmt.Printf("%d\n", lista[i]-lista[0])
			}
		}
	}
}

