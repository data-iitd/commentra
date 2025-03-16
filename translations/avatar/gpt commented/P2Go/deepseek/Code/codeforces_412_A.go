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

	// Read two integers n and k from input
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	// Read the string of values (v) from input
	v, _ := reader.ReadString('\n')
	v = strings.TrimSpace(v)

	// Define the directions for movement: LEFT and RIGHT
	d := []string{"LEFT", "RIGHT"}

	// Determine if we should move LEFT or RIGHT based on the position k
	// If k is closer to the start (LEFT), f will be True; otherwise, it will be False
	f := k - 1 < n - k

	// Calculate the minimum number of moves needed to reach the desired position
	m := min(k - 1, n - k)

	// Initialize an empty list to store the sequence of moves and prints
	var a []string

	// Append the necessary number of LEFT or RIGHT moves to the list based on the calculated minimum moves
	for i := 0; i < m; i++ {
		a = append(a, d[1-f]) // Append the opposite direction of f
	}

	// Append the print commands for each character in the string v
	// The slicing reverses the order of characters if moving RIGHT (f is True)
	for i := len(v) - 1; i >= 0; i -= 1 - 2*f {
		a = append(a, "PRINT "+string(v[i])) // Append the print command for the current character
		a = append(a, d[f])                  // Append the direction for the next move
	}

	// Print the final sequence of moves and print commands, excluding the last move
	for i := 0; i < len(a)-1; i++ {
		fmt.Println(a[i])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

