package main

import (
	"fmt"
)

func dfs(currpos int, arr []int, target int) bool {
	// Depth-first search method to find if the target position can be reached
	if currpos == target {
		return true // If current position is the target, return true
	}
	if currpos > len(arr) {
		return false // If current position exceeds array length, return false
	}

	teleport := dfs(currpos+arr[currpos-1], arr, target) // Recursive call with teleported position
	if teleport {
		return true // If teleportation leads to the target, return true
	}
	return false // Otherwise, return false
}

func main() {
	var n, goal int
	fmt.Scan(&n) // Reading the number of elements in the array
	fmt.Scan(&goal) // Reading the target position
	arr := make([]int, n-1) // Initializing the array with n-1 elements

	for i := 0; i < n-1; i++ {
		fmt.Scan(&arr[i]) // Reading the array elements
	}

	isFound := dfs(1, arr, goal) // Calling the dfs method with initial position 1
	if isFound {
		fmt.Println("YES") // If the target position is found, print "YES"
	} else {
		fmt.Println("NO") // Otherwise, print "NO"
	}
}

// <END-OF-CODE>
