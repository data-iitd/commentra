
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Get user input as a string and convert it to a list of integers
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	x, _ := strconv.Atoi(parts[0])
	y, _ := strconv.Atoi(parts[1])
	a, _ := strconv.Atoi(parts[2])
	b, _ := strconv.Atoi(parts[3])

	// Initialize an empty list to store the games
	games := [][2]int{}

	// Iterate through a range of numbers from a to x+1
	for i := a; i <= x; i++ {
		// If i is less than or equal to b, skip to the next iteration
		if i <= b {
			continue
		}
		// Iterate through a range of numbers from b to y+1
		for j := b; j <= y; j++ {
			// If i is greater than j, append the tuple (i, j) to the games list
			if i > j {
				games = append(games, [2]int{i, j})
			}
		}
	}

	// Print the length of the games list
	fmt.Println(len(games))
	// Iterate through the games list and print each tuple
	for _, game := range games {
		// Print the tuple as a string in the format "i j"
		fmt.Printf("%d %d\n", game[0], game[1])
	}
}

