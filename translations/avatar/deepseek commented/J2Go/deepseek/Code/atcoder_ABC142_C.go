package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Step 1: Read the input value N, which represents the number of elements.
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := fmt.Sscanf(scanner.Text(), "%d", &N)

	// Step 2: Create a map idorder to store the elements and their corresponding positions.
	idorder := make(map[int]int)

	// Step 3: Read each element and store its value and position in the map.
	for i := 1; i <= N; i++ {
		scanner.Scan()
		var A int
		fmt.Sscanf(scanner.Text(), "%d", &A)
		idorder[A] = i
	}

	// Step 4: Print the positions of the elements in the order they were read.
	for i := 1; i <= N; i++ {
		fmt.Printf("%d ", idorder[i])
	}
	fmt.Println() // Print a newline at the end
}

