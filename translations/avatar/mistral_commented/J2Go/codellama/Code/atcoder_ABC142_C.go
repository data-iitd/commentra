package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var N int
	var A int
	var idorder map[int]int
	var i int

	// Reading the number of elements from the user input
	N, _ = strconv.Atoi(os.Args[1])

	// Initializing the HashMap 'idorder'
	idorder = make(map[int]int)

	// Reading the elements and storing their corresponding indices in the HashMap
	for i = 1; i <= N; i++ {
		A, _ = strconv.Atoi(os.Args[i])
		idorder[A] = i
	}

	// Printing the indices of the elements in the order they were read
	for i = 1; i <= N; i++ {
		fmt.Printf("%d ", idorder[i])
	}

	// Closing the Scanner object to save system resources
	// scanner.close()
}

