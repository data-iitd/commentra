package main // Defining the main package

import (
	"fmt" // Importing the fmt package for input and output operations
)

func dfs(currPos int, arr []int, target int) bool { // Defining the recursive depth-first search function
	if currPos == target { // Base case: if the current position is the target position, return true
		return true
	}
	if currPos > len(arr) { // Base case: if the current position is out of the array bounds, return false
		return false
	}
	teleport := dfs(currPos+arr[currPos-1], arr, target) // Recursive call: try to teleport to the next position
	if teleport { // If teleportation was successful, return true
		return true
	}
	return false // If teleportation was not successful, return false
}

func main() { // Defining the main function
	var n, goal int
	fmt.Scan(&n) // Reading the number of positions in the array from the standard input
	fmt.Scan(&goal) // Reading the target position from the standard input
	arr := make([]int, n-1) // Creating a slice of size n-1 to store the positions of the teleportals
	for i := 0; i < n-1; i++ { // Reading the positions of the teleportals from the standard input and storing them in the slice
		fmt.Scan(&arr[i])
	}
	isFound := dfs(1, arr, goal) // Calling the depth-first search function with the initial position and the target position
	if isFound { // If the target position was found, print "YES" to the standard output
		fmt.Println("YES")
	} else { // If the target position was not found, print "NO" to the standard output
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
