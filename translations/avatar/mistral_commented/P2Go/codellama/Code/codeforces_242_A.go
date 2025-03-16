package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Get user input as a string and convert it to a list of integers
	input := "10 10 5 5"
	inputList := strings.Split(input, " ")
	x, _ := strconv.Atoi(inputList[0])
	y, _ := strconv.Atoi(inputList[1])
	a, _ := strconv.Atoi(inputList[2])
	b, _ := strconv.Atoi(inputList[3])

	// Initialize an empty list to store the games
	games := [][]int{}

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
				games = append(games, []int{i, j})
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

