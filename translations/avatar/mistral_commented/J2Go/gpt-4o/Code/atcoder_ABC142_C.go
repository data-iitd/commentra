package main

import (
	"fmt"
)

func main() {
	var N int // Declaring an integer variable 'N' to store the number of elements
	fmt.Scan(&N) // Reading the number of elements from the user input

	idorder := make(map[int]int) // Declaring and initializing a map 'idorder'

	// Reading the elements and storing their corresponding indices in the map
	for i := 1; i <= N; i++ {
		var A int // Reading an element 'A' from the user input
		fmt.Scan(&A) // Reading the element
		idorder[A] = i // Storing the index 'i' of the element 'A' in the map
	}

	// Printing the indices of the elements in the order they were read
	for i := 1; i <= N; i++ {
		fmt.Print(idorder[i], " ") // Printing the index of the current element
	}
}
