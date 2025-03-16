package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of items (n) from the input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	
	// Read the values (vStr) from the input and convert to a map
	scanner.Scan()
	vStr := scanner.Text()
	vMap := str2Map(vStr)
	
	// Read the costs (cStr) from the input and convert to a map
	scanner.Scan()
	cStr := scanner.Text()
	cMap := str2Map(cStr)
	
	// Initialize a variable to keep track of the maximum profit
	var max int
	
	// Calculate the profit for each item and sum up the positive profits
	for i := 0; i < n; i++ {
		profit := vMap[i] - cMap[i]
		// Only add to max if the profit is positive
		if profit > 0 {
			max += profit
		}
	}
	
	// Output the total maximum profit
	fmt.Println(max)
}

// Helper function to convert a space-separated string of integers into a map
func str2Map(str string) map[int]int {
	// Split the input string into an array of strings
	vArrStr := strings.Split(str, " ")
	
	// Create a map to hold the integer values with their corresponding indices
	ret := make(map[int]int)
	
	// Populate the map with values from the array
	for i, val := range vArrStr {
		key, _ := strconv.Atoi(val)
		ret[i] = key
	}
	
	// Return the populated map
	return ret
}

