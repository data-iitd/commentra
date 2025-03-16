package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declaring a map to hold integers (not used in the current code)
	var P map[int]int

	// Creating a new Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the number of elements (N) from the input
	var N int
	fmt.Scanln(&N)

	// Creating a map to store the mapping of integer values to their order of input
	idorder := make(map[int]int)

	// Looping through the range from 1 to N to read N integers
	for i := 1; i <= N; i++ {
		// Reading an integer A from the input
		var A int
		fmt.Scanln(&A)
		// Storing the integer A in the map with its order of input (i)
		idorder[A] = i
	}

	// Looping through the range from 1 to N to print the order of each integer
	for i := 1; i <= N; i++ {
		// Retrieving and printing the order of the integer i from the map
		fmt.Print(idorder[i])
		// Printing a space after each output
		fmt.Print(" ")
	}
}

