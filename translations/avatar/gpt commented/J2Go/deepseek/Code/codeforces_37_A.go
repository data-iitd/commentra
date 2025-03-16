package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner object to read input efficiently
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of integers to be processed
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize a map to store the frequency of each integer
	frequencyMap := make(map[int]int)

	// Loop through the input integers and populate the frequency map
	for i := 0; i < n; i++ {
		scanner.Scan()
		val, _ := strconv.Atoi(scanner.Text())
		// Update the count of the integer in the map
		frequencyMap[val]++
	}

	// Initialize a variable to track the maximum frequency found
	max := 0

	// Iterate through the entries in the frequency map to find the maximum frequency
	for _, value := range frequencyMap {
		// Update max if the current frequency is greater than the current max
		if value > max {
			max = value
		}
	}

	// Print the maximum frequency and the number of unique integers
	fmt.Println(strconv.Itoa(max) + strconv.Itoa(len(frequencyMap)))
}
