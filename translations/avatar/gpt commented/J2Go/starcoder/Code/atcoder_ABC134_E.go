package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of integers to process
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize a map to store integers and their counts
	m := make(map[int]int)

	// Process each integer input
	for n > 0 {
		// Read the next integer
		num, _ := strconv.Atoi(readLine(reader))

		// Check if there is no lower key in the map
		if _, ok := m[num];!ok {
			// If no lower key exists, increment the count for the current number
			m[num]++
		} else {
			// If there is a lower key, get that key and its count
			key := m[num]

			// If the count of the lower key is 1, remove it from the map
			if key == 1 {
				delete(m, num)
			} else {
				// Otherwise, decrement the count of the lower key
				m[num]--
			}

			// Increment the count for the current number
			m[num]++
		}

		// Decrement the number of integers to process
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

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

