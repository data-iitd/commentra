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

	// Read the maximum level
	maxLevelStr, _ := reader.ReadString('\n')
	maxLevel, _ := strconv.Atoi(strings.TrimSpace(maxLevelStr))

	// Read the two lists of integers
	xStr, _ := reader.ReadString('\n')
	yStr, _ := reader.ReadString('\n')

	// Split the input strings into lists
	xList := strings.Fields(xStr)
	yList := strings.Fields(yStr)

	// Convert the lists to integers and remove the first element from each list
	xList = xList[1:]
	yList = yList[1:]

	// Convert the lists to sets and check if there's a 0 in either set
	xSet := make(map[int]bool)
	ySet := make(map[int]bool)
	for _, num := range xList {
		numInt, _ := strconv.Atoi(num)
		xSet[numInt] = true
	}
	for _, num := range yList {
		numInt, _ := strconv.Atoi(num)
		ySet[numInt] = true
	}

	// If there's a 0 in either set, discard it from the set
	if _, exists := xSet[0]; exists {
		delete(xSet, 0)
	}
	if _, exists := ySet[0]; exists {
		delete(ySet, 0)
	}

	// Find the union of the two sets and check if its length is equal to the maximum level
	unionSet := make(map[int]bool)
	for num := range xSet {
		unionSet[num] = true
	}
	for num := range ySet {
		unionSet[num] = true
	}

	if len(unionSet) != maxLevel {
		fmt.Println("Oh, my keyboard!")
	} else {
		fmt.Println("I become the guy.")
	}
}
