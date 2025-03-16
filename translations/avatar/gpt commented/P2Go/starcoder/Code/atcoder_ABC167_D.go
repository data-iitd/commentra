package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Read input values for N and K
func main() {
	// Read the list L of length N
	L := strings.Split(os.Args[1], " ")
	// Insert a placeholder value at the beginning of the list
	L = append([]string{"-1"}, L...)
	// Initialize variables for path tracking and loop detection
	path := []string{"1"}  // Start the path with the first node
	ind := 0                // Index to track the position in the path
	count := 0              // Not used in the current logic
	x := 1                  // Current node starting from 1
	t := -1                 // To store the index of the start of the loop if found
	flag := false           // Flag to indicate if a loop is detected
	Hash := make(map[string]int)  // Dictionary to store the last index of each node

	// Iterate through the nodes to detect loops
	for i := 0; i < len(L); i++ {
		ne := L[x]  // Get the next node from the list L
		// Check if the next node has been visited before
		if Hash[ne]!= 0 {
			flag = true  // Set the flag to indicate a loop is found
			t = Hash[ne]  // Store the index where the loop starts
			break  // Exit the loop since a cycle is detected
		}
		// Append the next node to the path
		path = append(path, ne)
		ind++  // Increment the index
		Hash[ne] = ind  // Update the last index of the current node
		x = ind  // Move to the next node
	}

	// Check if a loop was detected
	if flag == true {
		loop := path[t:]  // Extract the loop from the path
		// Check if K is within the length of the path
		if len(path) >= int(os.Args[2]) {
			fmt.Println(path[int(os.Args[2]) - 1])  // Print the K-th node in the path
		} else {
			K := int(os.Args[2]) - len(path)  // Adjust K to account for the full path length
			K = K % len(loop)  // Get the position within the loop
			fmt.Println(loop[K])  // Print the K-th node in the loop
	} else {
		fmt.Println(path[int(os.Args[2]) - 1])  // If no loop, print the K-th node in the path
	}
}

