package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input n which represents the threshold for majority
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	// Read a line of input, split it into a list of strings, and store it in m
	mStr, _ := reader.ReadString('\n')
	m := strings.Fields(mStr)

	// Initialize a variable to track if a majority element is possible
	possible := true

	// Iterate through each unique element in the list m
	mSet := make(map[string]int)
	for _, elem := range m {
		mSet[elem]++
	}

	for _, count := range mSet {
		// Check if the count of the current element i is greater than or equal to n/2 + 1
		if count >= n/2+1 {
			// If it is, set possible to False and break the loop
			possible = false
			break
		}
	}

	// Print 'YES' if a majority element is not found, otherwise print 'NO'
	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

