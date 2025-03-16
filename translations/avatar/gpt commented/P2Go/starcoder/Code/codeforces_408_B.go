package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the first line of input which represents the colors bought
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	// Count the occurrences of each color bought using Counter
	bought_count := make(map[string]int)
	for _, color := range strings.Split(line, "") {
		bought_count[color]++
	}

	// Read the second line of input which represents the colors made
	scanner.Scan()
	line = scanner.Text()
	// Count the occurrences of each color made using Counter
	made_count := make(map[string]int)
	for _, color := range strings.Split(line, "") {
		made_count[color]++
	}

	// Initialize the result variable to store the total count of matched colors
	res := 0

	// Iterate through each color in the made_count
	for color := range made_count {
		// If a color made is not found in the bought colors, return -1
		if _, ok := bought_count[color];!ok {
			fmt.Println(-1)
			return
		}
		// Add the minimum of the bought and made counts for each color to the result
		res += min(bought_count[color], made_count[color])
	}

	// Print the total count of matched colors
	fmt.Println(res)
}

