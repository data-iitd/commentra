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

	// Read the maximum level of the set
	maxLevelStr, _ := reader.ReadString('\n')
	maxLevel, _ := strconv.Atoi(strings.TrimSpace(maxLevelStr))

	// Read the two lists, x and y, separated by a newline
	xStr, _ := reader.ReadString('\n')
	yStr, _ := reader.ReadString('\n')

	// Split the input strings into lists
	xList := strings.Fields(xStr)
	yList := strings.Fields(yStr)

	// Convert the first elements to integers and remove them from the lists
	xList = xList[1:]
	yList = yList[1:]

	// Convert both lists to sets for faster set operations
	xSet := make(map[string]bool)
	ySet := make(map[string]bool)

	for _, val := range xList {
		xSet[val] = true
	}

	for _, val := range yList {
		ySet[val] = true
	}

	// Combine both sets into a new set z
	z := make(map[string]bool)

	for val := range xSet {
		z[val] = true
	}

	for val := range ySet {
		z[val] = true
	}

	// Check if zero is present in the first set
	if _, exists := z["0"]; exists {
		// If it is, remove it
		delete(z, "0")
	}

	// Check if zero is present in the second set
	if _, exists := z["0"]; exists {
		// If it is, remove it
		delete(z, "0")
	}

	// Check if the size of the combined set is equal to the maximum level
	if len(z) != maxLevel {
		// If not, print an error message
		fmt.Println("Oh, my keyboard!")
	} else {
		// Else, print a success message
		fmt.Println("I become the guy.")
	}
}

