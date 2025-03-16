package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to define the main logic of the program
func main() {
	// Create a new reader for reading input
	reader := bufio.NewReader(os.Stdin)

	// Read input: number of elements 'n' and the difference 'k'
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	// Read input: list of elements 'elems'
	input, _ = reader.ReadString('\n')
	elemsStr := strings.Split(strings.TrimSpace(input), " ")
	elems := []int{}
	for _, elemStr := range elemsStr {
		elem, _ := strconv.Atoi(elemStr)
		elems = append(elems, elem)
	}

	// Helper function to check if all elements in a list are the same
	allSame := func(arr []int) bool {
		for i := 1; i < len(arr); i++ {
			if arr[i] != arr[0] {
				return false
			}
		}
		return true
	}

	// Check if all elements in the list are the same
	if allSame(elems) {
		// If all elements are the same, print 0 and exit
		fmt.Println(0)
		return
	}

	// Check if difference 'k' is 1
	if k == 1 {
		// If difference is 1, print -1 and exit
		fmt.Println(-1)
		return
	}

	// Check if last 'k' elements in the list are not all the same
	if !allSame(elems[k-1:]) {
		// If last 'k' elements are not all the same, print -1 and exit
		fmt.Println(-1)
		return
	}

	// Initialize target element
	target := elems[len(elems)-1]

	// Initialize list 'toDelete' to store elements to be deleted
	toDelete := elems[0 : k-1]

	// While 'toDelete' is not empty and its last element is 'target'
	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		// Pop the last element from 'toDelete'
		toDelete = toDelete[:len(toDelete)-1]
	}

	// Print the length of 'toDelete'
	fmt.Println(len(toDelete))
}
