package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of players (n) and the number of levels (levels)
	fmt.Print("Enter the number of players (n): ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Print("Enter the number of levels (levels): ")
	levels, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Initialize variables to keep track of sums and counts
	sum := 0
	sum2 := 0
	sum3 := 0

	// Create an array to store the levels completed by the first player
	arr := make([]int, levels)
	count := 0

	// Read the levels completed by the first player
	for i := 0; i < levels; i++ {
		fmt.Print("Enter the level completed by the first player: ")
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}

	// Read the number of additional levels completed by the second player
	fmt.Print("Enter the number of additional levels completed by the second player: ")
	level2, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Calculate the total number of levels completed by both players
	level3 := levels + level2

	// Create a new array to store levels completed by both players
	arr2 := make([]int, level3)

	// Copy levels from the first player's array to the new array
	for i := 0; i < arr.length; i++ {
		arr2[i] = arr[i]
	}

	// Read the levels completed by the second player and add them to the new array
	for i := arr.length; i < level3; i++ {
		fmt.Print("Enter the level completed by the second player: ")
		arr2[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}

	// Create an array to represent all levels (1 to n)
	arr3 := make([]int, n)
	j := 0

	// Fill arr3 with level numbers from 1 to n
	for i := 0; i < n; i++ {
		arr3[i] = ++j
	}

	// Check how many levels from arr3 are completed by either player
	for i := 0; i < n; i++ {
		for x := 0; x < arr2.length; x++ {
			// If a level is found in arr2, increment the count and break
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}

	// Determine if all levels have been completed by at least one player
	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

