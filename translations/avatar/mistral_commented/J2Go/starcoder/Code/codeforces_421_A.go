package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of test cases
	var n int
	fmt.Scanf("%d", &n)

	// Read the number of elements in the first list
	var a int
	fmt.Scanf("%d", &a)

	// Read the number of elements in the second list
	var b int
	fmt.Scanf("%d", &b)

	// Create slices to store the lists
	list1 := make([]int, a)
	list2 := make([]int, b)

	// Read and store the elements of the first and second lists
	for i := 0; i < a; i++ {
		fmt.Scanf("%d", &list1[i])
	}
	for i := 0; i < b; i++ {
		fmt.Scanf("%d", &list2[i])
	}

	// Iterate through the input array and print the corresponding number based on the presence of the element in list1
	for i := 0; i < n; i++ {
		if contains(list1, i+1) {
			fmt.Printf("1 ")
		} else {
			fmt.Printf("2 ")
		}
	}
}

// contains returns true if the given list contains the given element
func contains(list []int, element int) bool {
	for _, e := range list {
		if e == element {
			return true
		}
	}
	return false
}

