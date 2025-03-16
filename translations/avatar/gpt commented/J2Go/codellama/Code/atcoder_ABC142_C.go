package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the number of elements (N) from the input
	N, _ := strconv.Atoi(scanner.Text())

	// Creating a HashMap to store the mapping of integer values to their order of input
	idorder := make(map[int]int)

	// Looping through the range from 1 to N to read N integers
	for i := 1; i <= N; i++ {
		// Reading an integer A from the input
		A, _ := strconv.Atoi(scanner.Text())
		// Storing the integer A in the map with its order of input (i)
		idorder[A] = i
	}

	// Looping through the range from 1 to N to print the order of each integer
	for i := 1; i <= N; i++ {
		// Retrieving and printing the order of the integer i from the map
		fmt.Printf("%d ", idorder[i])
	}
}

