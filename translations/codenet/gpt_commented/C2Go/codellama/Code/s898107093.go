package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare pointers for storing team names and initialize scores
	var t, h []string
	var n int
	var taro, hanako int

	// Read the number of rounds (n) from input
	n, _ = strconv.Atoi(os.Args[1])

	// Allocate memory for team names for both players
	t = make([]string, n)
	h = make([]string, n)

	// Loop through each round to read team names and calculate scores
	for i := 0; i < n; i++ {
		// Read team names for both players
		t[i] = os.Args[2*i+2]
		h[i] = os.Args[2*i+3]

		// Compare team names and update scores based on the comparison
		if strings.Compare(t[i], h[i]) < 0 {
			// If Hanako's team name is lexicographically smaller, she gets 3 points
			hanako += 3
		}
		if strings.Compare(t[i], h[i]) > 0 {
			// If Taro's team name is lexicographically larger, he gets 3 points
			taro += 3
		}
		if strings.Compare(t[i], h[i]) == 0 {
			// If both team names are the same, both players get 1 point
			taro += 1
			hanako += 1
		}
	}

	// Output the final scores of Taro and Hanako
	fmt.Printf("%d %d\n", taro, hanako)
}

