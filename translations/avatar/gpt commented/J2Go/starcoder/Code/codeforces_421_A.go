package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the value of n
	fmt.Print("Enter the value of n: ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Read the value of a
	fmt.Print("Enter the value of a: ")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Read the value of b
	fmt.Print("Enter the value of b: ")
	b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Initialize two slices to store the elements of the two lists
	list1 := make([]int, a)
	list2 := make([]int, b)

	// Read 'a' integers into list1
	for i := 0; i < a; i++ {
		fmt.Print("Enter the value of list1: ")
		list1[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}

	// Read 'b' integers into list2
	for i := 0; i < b; i++ {
		fmt.Print("Enter the value of list2: ")
		list2[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}

	// Iterate from 0 to n-1 to check the presence of each index in list1
	for i := 0; i < n; i++ {
		// If the current index + 1 is in list1, print 1
		if contains(list1, i+1) {
			fmt.Println(1)
		} else {
			// Otherwise, print 2
			fmt.Println(2)
		}
	}
}

// contains returns true if the given integer is present in the given slice
func contains(list []int, num int) bool {
	for _, v := range list {
		if v == num {
			return true
		}
	}
	return false
}

