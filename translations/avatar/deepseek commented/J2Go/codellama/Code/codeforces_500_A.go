package main

import (
	"fmt"
	"os"
	"strconv"
)

func dfs(currpos int, arr []int, target int) bool {
	// Depth-first search method to find if the target position can be reached
	if currpos == target {
		return true // If current position is the target, return true
	}
	if currpos == len(arr)+1 {
		return false // If current position exceeds array length, return false
	}

	teleport := dfs(currpos+arr[currpos-1], arr, target) // Recursive call with teleported position
	if teleport {
		return true // If teleportation leads to the target, return true
	}
	return false // Otherwise, return false
}

func main() {
	// Main method where the program execution begins
	sc := bufio.NewScanner(os.Stdin) // Creating a Scanner object to read input
	sc.Split(bufio.ScanWords)
	var n int // Reading the number of elements in the array
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	var goal int // Reading the target position
	sc.Scan()
	goal, _ = strconv.Atoi(sc.Text())
	arr := make([]int, n-1) // Initializing the array with n-1 elements

	for i := 0; i < n-1; i++ {
		sc.Scan()
		arr[i], _ = strconv.Atoi(sc.Text()) // Reading the array elements
	}

	isFound := dfs(1, arr, goal) // Calling the dfs method with initial position 1
	if isFound {
		fmt.Println("YES") // If the target position is found, print "YES"
	} else {
		fmt.Println("NO") // Otherwise, print "NO"
	}

	sc.Close() // Closing the Scanner object
}

