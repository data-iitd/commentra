package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of elements (n) and the parameter (k)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])
	
	// Read the list of elements
	input, _ = reader.ReadString('\n')
	elemsStr := strings.Split(strings.TrimSpace(input), " ")
	elems := make([]int, n)
	for i, elem := range elemsStr {
		elems[i], _ = strconv.Atoi(elem)
	}
	
	// Define a function to check if all elements in a list are the same
	allSame := func(arr []int) bool {
		for i := 1; i < len(arr); i++ {
			if arr[i] != arr[0] {
				return false
			}
		}
		return true
	}
	
	// Check if all elements in the list are the same
	if allSame(elems) {
		// If all elements are the same, print 0 and return
		fmt.Println(0)
		return
	}
	
	// If k is 1, print -1 and return
	if k == 1 {
		fmt.Println(-1)
		return
	}
	
	// Check if elements from index k-1 to the end are all the same
	if !allSame(elems[k-1:]) {
		// If not, print -1 and return
		fmt.Println(-1)
		return
	}
	
	// Set the target to the last element of the list
	target := elems[len(elems)-1]
	
	// Initialize to_delete as elements from the start to k-1
	toDelete := elems[:k-1]
	
	// Remove elements from to_delete that are equal to target until a different element is found
	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		toDelete = toDelete[:len(toDelete)-1]
	}
	
	// Print the length of to_delete
	fmt.Println(len(toDelete))
}

