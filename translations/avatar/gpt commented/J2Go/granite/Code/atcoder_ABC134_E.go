
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of integers to process
	n, _ := strconv.Atoi(reader.ReadLine())

	// Initialize a map to store integers and their counts
	m := make(map[int]int)

	// Process each integer input
	for n > 0 {
		// Read the next integer
		num, _ := strconv.Atoi(reader.ReadLine())

		// Check if there is no lower key in the map
		if _, ok := m[num];!ok {
			// If no lower key exists, increment the count for the current number
			m[num]++
		} else {
			// If there is a lower key, get that key and its count
			key := num - 1
			val := m[key]

			// If the count of the lower key is 1, remove it from the map
			if val == 1 {
				delete(m, key)
			} else {
				// Otherwise, decrement the count of the lower key
				m[key]--
			}

			// Increment the count for the current number
			m[num]++
		}

		n--
	}

	// Initialize a variable to hold the final answer
	ans := 0

	// Sum up all the counts in the map
	for _, val := range m {
		ans += val
	}

	// Print the final answer
	fmt.Println(ans)
}

