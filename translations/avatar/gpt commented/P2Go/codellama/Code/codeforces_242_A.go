package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read input values for x, y, a, and b and convert them to integers
	x, y, a, b := readInput()

	// Initialize an empty list to store valid game pairs
	games := make([][]int, 0)

	// Iterate over the range from a to x (inclusive)
	for i := a; i <= x; i++ {
		// Skip the iteration if i is less than or equal to b
		if i <= b {
			continue
		}

		// Iterate over the range from b to y (inclusive)
		for j := b; j <= y; j++ {
			// Check if the current i is greater than j
			if i > j {
				// If the condition is met, append the pair (i, j) to the games list
				games = append(games, []int{i, j})
			}
		}
	}

	// Print the total number of valid game pairs found
	fmt.Println(len(games))

	// Print each valid game pair
	for _, game := range games {
		fmt.Printf("%d %d\n", game[0], game[1])
	}
}

func readInput() (int, int, int, int) {
	// Read input values for x, y, a, and b
	input := strings.Split(strings.TrimSpace(readLine()), " ")

	// Convert input values to integers
	x, _ := strconv.Atoi(input[0])
	y, _ := strconv.Atoi(input[1])
	a, _ := strconv.Atoi(input[2])
	b, _ := strconv.Atoi(input[3])

	return x, y, a, b
}

func readLine() string {
	var line string
	if _, err := fmt.Scan(&line); err != nil {
		panic(err)
	}
	return line
}

