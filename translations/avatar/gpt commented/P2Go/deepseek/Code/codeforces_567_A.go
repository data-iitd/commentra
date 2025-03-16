package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer input (not used later in the code)
	_, _ = reader.ReadString('\n')

	// Initialize an empty list to store integers
	var lista []int

	// Read a line of input, split it into strings, convert each string to an integer, and store it in lista
	input, _ := reader.ReadString('\n')
	elements := strings.Fields(input)
	for _, element := range elements {
		num, _ := strconv.Atoi(element)
		lista = append(lista, num)
	}

	// Iterate through the indices of the lista
	for i := 0; i < len(lista); i++ {
		// Handle the first element in the list
		if i == 0 {
			// Calculate and print the difference between the second and first elements,
			// and the difference between the last and first elements
			fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[len(lista)-1]-lista[i])
			continue // Skip to the next iteration
		}

		// Handle the last element in the list
		if i == len(lista)-1 {
			// Calculate and print the difference between the last and second-to-last elements,
			// and the difference between the last and the first elements
			fmt.Printf("%d %d\n", lista[len(lista)-1]-lista[len(lista)-2], lista[len(lista)-1]-lista[0])
			continue // Skip to the next iteration
		}

		// For elements in the middle of the list
		if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
			// If the difference to the next element is smaller, print that difference
			fmt.Printf("%d ", lista[i+1]-lista[i])
		} else {
			// Otherwise, print the difference to the previous element
			fmt.Printf("%d ", lista[i]-lista[i-1])
		}

		// Compare the difference to the last element with the difference to the first element
		if lista[len(lista)-1]-lista[i] > lista[i]-lista[0] {
			// If the difference to the last element is larger, print that difference
			fmt.Printf("%d\n", lista[len(lista)-1]-lista[i])
		} else {
			// Otherwise, print the difference to the first element
			fmt.Printf("%d\n", lista[i]-lista[0])
		}
	}
