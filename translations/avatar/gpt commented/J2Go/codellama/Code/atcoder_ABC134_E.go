
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := make([]string, 0)
	sc = append(sc, os.Args[1:]...)
	sc = append(sc, strings.Split(string(os.Stdin.Read(make([]byte, 1000000))), " ")...)

	// Read the number of integers to process
	n, _ := strconv.Atoi(sc[0])
	sc = sc[1:]

	// Initialize a TreeMap to store integers and their counts
	map := make(map[int]int)

	// Process each integer input
	for n > 0 {
		// Read the next integer
		num, _ := strconv.Atoi(sc[0])
		sc = sc[1:]

		// Check if there is no lower key in the map
		if _, ok := map[num-1]; !ok {
			// If no lower key exists, increment the count for the current number
			map[num]++
		} else {
			// If there is a lower key, get that key and its count
			key := num - 1
			val := map[key]

			// If the count of the lower key is 1, remove it from the map
			if val == 1 {
				delete(map, key)
			} else {
				// Otherwise, decrement the count of the lower key
				map[key] = val - 1
			}

			// Increment the count for the current number
			map[num]++
		}

		n--
	}

	// Initialize a variable to hold the final answer
	ans := 0

	// Sum up all the counts in the map
	for key, val := range map {
		ans += val
	}

	// Print the final answer
	fmt.Println(ans)
}

