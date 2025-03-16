package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a new scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the first line of input which contains the number of elements 'n' in the list 'w'
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initializing an empty slice 'w' to store the elements
	var w []int

	// Reading the next 'n' lines of input which contain the elements of the list 'w'
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		w = append(w, num)
	}

	// Initializing an empty slice 'd' to store the indices of the elements that satisfy the condition
	var d []int

	// Iterating through each element 'i' in the list 'w'
	for i := 0; i < n; i++ {
		// Calculating the average of the remaining sum of elements after removing the current element 'w[i]'
		// and checking if it's equal to the current element 'w[i]'
		sum := 0
		for j := 0; j < n; j++ {
			if j != i {
				sum += w[j]
			}
		}
		if float64(sum)/(n-1) == float64(w[i]) {
			// If the condition is true, append the index 'i+1' to the slice 'd'
			d = append(d, i+1)
		}
	}

	// Printing the length of the slice 'd'
	fmt.Println(len(d))

	// Printing the elements of the slice 'd' separated by a space
	for i, v := range d {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Println()
}

