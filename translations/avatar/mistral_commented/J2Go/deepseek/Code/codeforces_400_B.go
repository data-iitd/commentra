package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initializing Scanner object for reading input
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the first two integers from the input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	// Creating a slice of strings to store input strings
	arrs := make([]string, n)

	// Iterating through the slice and storing each string
	for i := 0; i < n; i++ {
		scanner.Scan()
		arrs[i] = scanner.Text()
	}

	// Initializing a slice to store the length of substrings between "G" and "S"
	length := make([]int, n)
	index := 0
	returnDex := 0

	// Iterating through each string in the slice and finding the length of substrings between "G" and "S"
	for _, tmp := range arrs {
		dexG := strings.Index(tmp, "G")
		dexS := strings.Index(tmp, "S")

		// Checking if "G" comes before "S" in the current string
		if dexG > dexS {
			returnDex = -1
			break
		}

		// Storing the length of the substring between "G" and "S" in the length slice
		length[index] = dexS - dexG
		index++
	}

	// Creating a map to store the unique lengths of substrings
	uniqueLengths := make(map[int]bool)

	// Iterating through the length slice and adding each unique length to the map
	for _, len := range length {
		if len > 0 {
			uniqueLengths[len] = true
		}
	}

	// Printing the size of the map if there is a string with "G" before "S"
	if returnDex == -1 {
		fmt.Println(returnDex)
	} else {
		fmt.Println(len(uniqueLengths))
	}
}
