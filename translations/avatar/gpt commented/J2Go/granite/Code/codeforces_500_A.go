
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

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
	// Create a Scanner object for input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of positions (n) and the target position (goal)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	goal, _ := strconv.Atoi(scanner.Text())

	// Initialize an array to hold the teleportation values
	arr := make([]int, n-1)

	// Populate the array with teleportation values from input
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		arr[i], _ = strconv.Atoi(scanner.Text())
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

