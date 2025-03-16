package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the integer n
	var n int
	fmt.Fscan(reader, &n)

	// Read the list of strings s
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	stringsList := strings.Split(s, " ")

	// Create a map to count occurrences of each string
	counts := make(map[string]int)
	for _, str := range stringsList {
		counts[str]++
	}

	// Reverse the list s
	reversedList := make([]string, len(stringsList))
	for i := 0; i < len(stringsList); i++ {
		reversedList[i] = stringsList[len(stringsList)-1-i]
	}

	// Initialize variables
	c, a := -1, ""

	// Find the string with the maximum count
	maxCount := 0
	for _, count := range counts {
		if count > maxCount {
			maxCount = count
		}
	}

	// Iterate over the counts map
	for str, count := range counts {
		if count == maxCount {
			// Check the index in the reversed list
			index := indexOf(reversedList, str)
			if index > c {
				a = str
				c = index
			}
		}
	}

	// Print the result
	fmt.Println(a)
}

// Helper function to find the index of a string in a slice
func indexOf(slice []string, str string) int {
	for i, v := range slice {
		if v == str {
			return i
		}
	}
	return -1
}
