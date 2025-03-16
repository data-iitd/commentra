package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Depth-first search (DFS) method to determine if the target can be reached
func dfs(currpos int, arr []int, target int) bool {
	// Base case: if the current position equals the target, return true
	if currpos == target {
		return true
	}

	// Base case: if the current position exceeds the bounds of the array, return false
	if currpos == len(arr)+1 {
		return false
	}

	// Recursive case: attempt to teleport to the next position based on the current array value
	teleport := dfs(currpos+arr[currpos-1], arr, target)

	// If teleporting leads to the target, return true
	if teleport {
		return true
	}

	// If no valid path found, return false
	return false
}

func main() {
	// Read the number of positions (n) and the target position (goal)
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of positions (n): ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Print("Enter the target position (goal): ")
	input, _ = reader.ReadString('\n')
	goal, _ := strconv.Atoi(strings.TrimSpace(input))

	// Initialize an array to hold the teleportation values
	arr := make([]int, n-1)

	// Populate the array with teleportation values from input
	for i := 0; i < n-1; i++ {
		fmt.Print("Enter the teleportation value for position ", i+1, ": ")
		input, _ = reader.ReadString('\n')
		arr[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Call the DFS function starting from position 1 to check if the goal can be reached
	isFound := dfs(1, arr, goal)

	// Output the result based on whether the goal was found
	if isFound {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// 