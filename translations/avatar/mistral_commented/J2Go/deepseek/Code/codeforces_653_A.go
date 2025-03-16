package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements in the list from the user input
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Create a slice to store the unique and sorted list elements
	a := make([]int, 0, n)

	// Read the list elements from the user input
	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')
		value, _ := strconv.Atoi(strings.TrimSpace(input))
		a = append(a, value)
	}

	// Sort the slice
	sort.Ints(a)

	// Remove duplicates
	uniqueA := removeDuplicates(a)

	// Check if there exists a sequence of three consecutive elements with a difference of 1
	found := false
	for i := 0; i < len(uniqueA); i++ {
		if i+1 < len(uniqueA) && i+2 < len(uniqueA) {
			if uniqueA[i]+1 == uniqueA[i+1] && uniqueA[i+1]+1 == uniqueA[i+2] {
				found = true
				break
			}
		}
	}

	// Write the output to the console
	if found {
		fmt.Fprintln(writer, "YES")
	} else {
		fmt.Fprintln(writer, "NO")
	}
}

// Helper function to remove duplicates from a slice
func removeDuplicates(a []int) []int {
	uniqueMap := make(map[int]bool)
	uniqueA := []int{}
	for _, value := range a {
		if !uniqueMap[value] {
			uniqueMap[value] = true
			uniqueA = append(uniqueA, value)
		}
	}
	return uniqueA
}

