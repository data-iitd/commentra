
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables for storing team names and scores
	var n int
	var taro, hanako int
	var t, h []string

	// Read the number of rounds (n) from input
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)

	// Loop through each round to read team names and calculate scores
	for i := 0; i < n; i++ {
		// Read team names for both players
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%s\n", &t[i])
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%s\n", &h[i])

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
	fmt.Println(strconv.Itoa(taro), strconv.Itoa(hanako))
}

