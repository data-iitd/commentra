
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a scanner to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Reading the number of elements in the array
	n, _ := strconv.Atoi(read(reader))

	// Initializing an array of size n + 1 to store the input integers
	array := make([]int, n+1)

	// Loop to read n integers from the user and store them in the array
	for i := 1; i <= n; i++ {
		array[i], _ = strconv.Atoi(read(reader)) // Storing each integer in the array
	}

	// Initializing counters for odd and even numbers and their latest indices
	odd := 0
	even := 0
	odd_ind := 0
	even_ind := 0

	// Loop to count odd and even numbers and track their latest indices
	for i := 1; i <= n; i++ {
		if array[i]%2 == 0 { // Checking if the number is even
			even++ // Incrementing the even counter
			even_ind = i // Updating the index of the last even number
		} else { // The number is odd
			odd++ // Incrementing the odd counter
			odd_ind = i // Updating the index of the last odd number
		}
	}

	// Comparing the counts of odd and even numbers to determine which index to print
	if odd > even {
		fmt.Println(even_ind) // Print the index of the last even number if there are more odds
	} else {
		fmt.Println(odd_ind) // Print the index of the last odd number otherwise
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

