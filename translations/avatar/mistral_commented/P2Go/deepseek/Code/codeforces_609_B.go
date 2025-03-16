package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input as a list of integers
func _input() []int {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	parts := strings.Fields(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func main() {
	// Read number of elements 'n' and size 'm' of the list 'lst'
	parts := _input()
	n := parts[0]
	m := parts[1]

	// Read the list 'lst'
	lst := _input()

	// Initialize an empty dictionary 'l' to store the frequency of each element
	l := make(map[int]int)

	// Iterate through each element in the list 'lst'
	for i := 0; i < n; i++ {
		// If the current element is not already present in the dictionary 'l'
		if _, exists := l[lst[i]]; !exists {
			// Add the current element to the dictionary 'l' with a frequency of 1
			l[lst[i]] = 1
		} else {
			// Increment the frequency of the current element in the dictionary 'l'
			l[lst[i]] += 1
		}
	}

	// Initialize result variable 'res' to 0
	res := 0

	// Iterate through each element in the list 'lst'
	for i := 0; i < n; i++ {
		// If the frequency of the current element in the dictionary 'l' is greater than 1
		if l[lst[i]] > 1 {
			// Calculate the number of elements that have a smaller frequency than the current element
			// and add it to the result variable 'res'
			res += n - i - l[lst[i]]
			// Decrease the frequency of the current element in the dictionary 'l' by 1
			l[lst[i]] -= 1
		} else {
			// Calculate the number of elements that have not been processed yet and add it to the result variable 'res'
			res += n - i - 1
		}
	}

	// Print the final result
	fmt.Println(res)
}
