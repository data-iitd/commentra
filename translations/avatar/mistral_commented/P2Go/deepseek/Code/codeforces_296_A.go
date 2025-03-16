package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read integer 'n'
	n, _ := strconv.Atoi(readLine(reader))
	
	// Read list 'm' as a single string and split it into characters
	m := strings.Fields(readLine(reader))
	
	// Initialize a boolean variable 'possible' with a default value of true
	possible := true
	
	// Create a map to count occurrences of each character in the list 'm'
	countMap := make(map[string]int)
	
	// Iterate through each character 'i' in the list 'm'
	for _, i := range m {
		countMap[i]++
	}
	
	// Iterate through each unique character 'i' in the map 'countMap'
	for i := range countMap {
		// Check if the character 'i' appears more than 'n/2 + 1' times
		if countMap[i] >= n/2+1 {
			// If the condition is true, set 'possible' to false
			possible = false
			break
		}
	}
	
	// Print 'YES' if 'possible' is still true, otherwise print 'NO'
	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// Helper function to read a line from the reader
func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}
