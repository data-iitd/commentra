

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, _ := strconv.Atoi(reader.ReadLine()[2:])  // Read the number of elements
	l := make([]int, n)  // Initialize the list of elements

	// Read the list of elements
	input := reader.ReadLine()
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(input[i*2 : i*2+2])
	}

	// Initialize variables
	high := 1
	tower := n
	maximum := 1

	// Sort the list
	for i := 1; i < n; i++ {
		if l[i] == l[i-1] {  // Check if the current element is equal to the previous element
			tower--  // Decrement the tower count
			high++  // Increment the high count
		} else {
			if high > maximum {  // Check if the current high is greater than the maximum
				maximum = high  // Update the maximum
			}
			high = 1  // Reset high to 1
		}
	}

	if high > maximum {  // Check if the final high is greater than the maximum
		maximum = high  // Update the maximum
	}

	// Print the result
	fmt.Println(maximum, tower)
}
