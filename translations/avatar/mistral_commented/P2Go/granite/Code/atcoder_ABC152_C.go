
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Get the number of elements in the array from user input
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Initialize an empty slice 'n' of size N
	n := make([]int, N)

	// Get the elements of the array from user input and store them in 'n'
	input := bufio.NewReader(os.Stdin).Scan()
	for i := 0; i < N; i++ {
		n[i], _ = strconv.Atoi(input.Text())
		input = bufio.NewReader(os.Stdin).Scan()
	}

	// Initialize variables 'a' and 'pos'
	a := 1
	pos := 0

	// Iterate through the array 'n' starting from the second element
	for i := 1; i < N; i++ {
		// Check if the current element is greater than the previous one
		if n[pos] > n[i] {
			// Increment the variable 'a' if the condition is true
			a += 1
			// Update the position of the previous greater element
			pos = i
		}
	}

	// Print the value of 'a' as the output
	fmt.Println(a)
}
