
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Take the number of elements in the list as input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Initialize an empty list 'l' to store the input elements
	l := make([]int, n)

	// Read the list elements from the standard input, convert them to integers and append to the list
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
	}

	// Initialize variables 'high' and 'tower' with initial values
	high := 1
	tower := n

	// Iterate through the list starting from the second element
	for i := 1; i < n; i++ {
		// If the current element is same as the previous one, decrement 'tower' and increment 'high'
		if l[i] == l[i-1] {
			tower -= 1
			high += 1
		}
		// If the current element is different, check if 'high' is greater than the current maximum and update it if true
		else {
			if high > maximum {
				maximum = high
			}
			high = 1
		}
	}

	// Check if the last 'high' value is greater than the current maximum and update it if true
	if high > maximum {
		maximum = high
	}

	// Print the final result
	fmt.Println(maximum, tower)
}
