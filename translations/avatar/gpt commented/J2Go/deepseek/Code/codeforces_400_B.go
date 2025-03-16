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
	
	// Read the number of strings (n) and the number of queries (m)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	
	// Initialize an array to store the strings
	arrs := make([]string, n)
	
	// Read n strings from the input
	for i := 0; i < n; i++ {
		scanner.Scan()
		arrs[i] = scanner.Text()
	}
	
	// Initialize an array to store the lengths of segments between 'G' and 'S'
	length := make([]int, n)
	index := 0
	returnDex := 0
	
	// Iterate through each string to find the indices of 'G' and 'S'
	for _, tmp := range arrs {
		dexG := strings.Index(tmp, "G") // Find the index of 'G'
		dexS := strings.Index(tmp, "S") // Find the index of 'S'
		
		// If 'G' appears after 'S', set returnDex to -1
		if dexG > dexS {
			returnDex = -1
		}
		
		// Calculate the length between 'G' and 'S' and store it in the length array
		length[index] = dexS - dexG
		index++
	}
	
	// Use a map to store unique lengths
	set := make(map[int]bool)
	
	// Add each length to the map to ensure uniqueness
	for _, len := range length {
		if len >= 0 {
			set[len] = true
		}
	}
	
	// Check if returnDex was set to -1 and print the appropriate result
	if returnDex == -1 {
		fmt.Println(returnDex) // Print -1 if 'G' is after 'S' in any string
	} else {
		fmt.Println(len(set)) // Print the number of unique lengths
	}
}
