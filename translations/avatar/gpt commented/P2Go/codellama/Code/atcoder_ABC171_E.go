package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input N (not used in further calculations)
	N, _ := strconv.Atoi(os.Args[1])

	// Read a list of integers from input and convert them to a list of integers
	a := strings.Split(os.Args[2], " ")
	for i, v := range a {
		a[i], _ = strconv.Atoi(v)
	}

	// Calculate the total using the XOR operation across all elements in the list 'a'
	total := 0
	for _, v := range a {
		total ^= v
	}

	// For each element in the list 'a', compute the XOR with 'total' and print the results
	// The results are converted to strings and joined with a space for output
	for _, v := range a {
		fmt.Printf("%d ", v^total)
	}
}

