package main

import (
	"fmt"
)

func main() {
	// Step 1: Read the input value N, which represents the number of elements.
	var N int
	fmt.Scan(&N)

	// Step 2: Create a map idorder to store the elements and their corresponding positions.
	idorder := make(map[int]int)

	// Step 3: Read each element and store its value and position in the map.
	for i := 1; i <= N; i++ {
		var A int
		fmt.Scan(&A)
		idorder[A] = i
	}

	// Step 4: Print the positions of the elements in the order they were read.
	for i := 1; i <= N; i++ {
		fmt.Print(idorder[i], " ")
	}
}

// <END-OF-CODE>
