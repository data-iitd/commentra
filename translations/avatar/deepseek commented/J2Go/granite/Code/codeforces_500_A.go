
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func dfs(currpos int, arr []int, target int) bool {
	// Depth-first search method to find if the target position can be reached
	if currpos == target {
		return true
	}
	if currpos == len(arr)+1 {
		return false
	}

	teleport := dfs(currpos+arr[currpos-1], arr, target) // Recursive call with teleported position
	if teleport {
		return true
	}
	return false
}

func main() {
	// Main method where the program execution begins
	reader := bufio.NewReader(os.Stdin) // Creating a bufio.Reader object to read input
	fmt.Print("Enter the number of elements in the array: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0:1]) // Reading the number of elements in the array
	fmt.Print("Enter the target position: ")
	goal, _ := strconv.Atoi(reader.ReadLine()[0:1]) // Reading the target position
	arr := make([]int, n-1) // Initializing the array with n-1 elements

	for i := 0; i < n-1; i++ {
		fmt.Print("Enter element ", i+1, ": ")
		arr[i], _ = strconv.Atoi(reader.ReadLine()[0:1]) // Reading the array elements
	}

	isFound := dfs(1, arr, goal) // Calling the dfs method with initial position 1
	if isFound {
		fmt.Println("YES") // If the target position is found, print "YES"
	} else {
		fmt.Println("NO") // Otherwise, print "NO"
	}
}

