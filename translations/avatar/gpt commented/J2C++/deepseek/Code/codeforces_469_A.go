package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of players (n) and the number of levels (levels)
	scanner.Scan()
	n := 0
	fmt.Sscan(scanner.Text(), &n)
	
	scanner.Scan()
	levels := 0
	fmt.Sscan(scanner.Text(), &levels)
	
	// Initialize variables to keep track of sums and counts
	sum := 0
	sum2 := 0
	sum3 := 0
	
	// Create a slice to store the levels completed by the first player
	arr := make([]int, levels)
	count := 0
	
	// Read the levels completed by the first player
	for i := 0; i < levels; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &arr[i])
	}
	
	// Read the number of additional levels completed by the second player
	scanner.Scan()
	level2 := 0
	fmt.Sscan(scanner.Text(), &level2)
	
	// Calculate the total number of levels completed by both players
	level3 := levels + level2
	
	// Create a new slice to store levels completed by both players
	arr2 := make([]int, level3)
	
	// Copy levels from the first player's slice to the new slice
	for i := 0; i < len(arr); i++ {
		arr2[i] = arr[i]
	}
	
	// Read the levels completed by the second player and add them to the new slice
	for i := len(arr); i < level3; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &arr2[i])
	}
	
	// Create a slice to represent all levels (1 to n)
	arr3 := make([]int, n)
	j := 0
	
	// Fill arr3 with level numbers from 1 to n
	for i := 0; i < n; i++ {
		arr3[i] = ++j
	}
	
	// Check how many levels from arr3 are completed by either player
	for i := 0; i < n; i++ {
		for x := 0; x < len(arr2); x++ {
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
