package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object for input and PrintWriter for output
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)

	// Initialize an array to store the elements
	ara := make([]int, n)

	// Create a map to count the frequency of each element
	freqMap := make(map[int]int)

	// Read elements and populate the frequency map
	for i := 0; i < n; i++ {
		scanner.Scan()
		v, _ := fmt.Sscan(scanner.Text(), &v)
		ara[i] = v
		// If the element is not in the map, add it with a count of 1
		if _, exists := freqMap[v]; !exists {
			freqMap[v] = 1
		} else {
			// If it is already in the map, increment its count
			freqMap[v]++
		}
	}

	// Find the maximum frequency among the elements
	maxFreq := 0
	for _, count := range freqMap {
		if count > maxFreq {
			maxFreq = count
		}
	}

	// Create another map to track the order of elements while checking frequency
	orderMap := make(map[int]int)

	// Iterate through the original array to find the first element with maximum frequency
	for i := 0; i < n; i++ {
		if _, exists := orderMap[ara[i]]; !exists {
			orderMap[ara[i]] = 1
			// Check if the current element's frequency matches the maximum frequency
			if orderMap[ara[i]] == maxFreq {
				fmt.Fprintln(writer, ara[i])
				break
			}
		} else {
			// Increment the count for the existing element
			orderMap[ara[i]]++
			// Check if the current element's frequency matches the maximum frequency
			if orderMap[ara[i]] == maxFreq {
				fmt.Fprintln(writer, ara[i])
				break
			}
		}
	}
}

