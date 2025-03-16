
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(strings.TrimSpace(string(read())))

	// Read the list of elements
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(strings.TrimSpace(string(read())))
	}

	// Initialize variables
	high := 1
	tower := n
	maximum := 1

	// Sort the list
	sort.Ints(l)

	// Loop through the sorted list
	for i := 1; i < n; i++ {
		if l[i] == l[i-1] { // Check if the current element is equal to the previous element
			tower -= 1 // Decrement the tower count
			high += 1 // Increment the high count
		} else {
			if high > maximum { // Check if the current high is greater than the maximum
				maximum = high // Update the maximum
			}
			high = 1 // Reset high to 1
		}
	}

	if high > maximum { // Check if the final high is greater than the maximum
		maximum = high // Update the maximum
	}

	// Print the result
	fmt.Println(maximum, tower)
}

func read() (input []byte) {
	input = make([]byte, 1024)
	for {
		n, err := f.Read(input)
		if err != nil {
			return input[:n]
		}
	}
}

