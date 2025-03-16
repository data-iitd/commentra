package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a buffered reader to read input efficiently
	reader := bufio.NewReader(os.Stdin)

	// Read the number of integers
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Convert string to integer

	// Create a map to store the frequency of each integer
	frequencyMap := make(map[int]int)

	// Read n integers and update their counts in the map
	for i := 0; i < n; i++ {
		valStr, _ := reader.ReadString('\n')
		val, _ := strconv.Atoi(valStr[:len(valStr)-1]) // Convert string to integer
		frequencyMap[val]++
	}

	// Initialize max to the smallest possible integer value
	max := 0

	// Iterate through the map to find the maximum count
	for _, value := range frequencyMap {
		if value > max {
			max = value
		}
	}

	// Print the maximum count and the size of the map
	fmt.Println(max, len(frequencyMap))
}

// <END-OF-CODE>
