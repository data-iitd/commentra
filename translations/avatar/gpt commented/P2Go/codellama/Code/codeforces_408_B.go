package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solution() {
	// Read the first line of input which represents the colors bought
	line := readLine()
	// Count the occurrences of each color bought using map
	boughtCount := make(map[string]int)
	for _, color := range strings.Split(line, "") {
		boughtCount[color]++
	}

	// Read the second line of input which represents the colors made
	line = readLine()
	// Count the occurrences of each color made using map
	madeCount := make(map[string]int)
	for _, color := range strings.Split(line, "") {
		madeCount[color]++
	}

	// Initialize the result variable to store the total count of matched colors
	res := 0

	// Iterate through each color in the made_count
	for color, madeCount := range madeCount {
		// If a color made is not found in the bought colors, return -1
		if _, found := boughtCount[color]; !found {
			fmt.Println(-1)
			return
		}
		// Add the minimum of the bought and made counts for each color to the result
		res += min(boughtCount[color], madeCount)
	}

	// Print the total count of matched colors
	fmt.Println(res)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func main() {
	// Set the number of test cases (currently set to 1)
	t := 1
	// Loop through each test case
	for i := 0; i < t; i++ {
		solution()
	}
}

