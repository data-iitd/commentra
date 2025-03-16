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
	// Use bufio.Scanner to read input and bufio.Writer to write output
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of integers from input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize a slice to store the integers
	a := make([]int, 0, n)

	// Read n integers from input and add them to the slice
	for i := 0; i < n; i++ {
		scanner.Scan()
		value, _ := strconv.Atoi(scanner.Text())
		a = append(a, value)
	}

	// Remove duplicates, sort the slice, and collect it back into a slice
	sort.Ints(a)
	a = unique(a)

	// Initialize a flag to check for consecutive triplets
	found := false

	// Check for three consecutive integers in the sorted slice
	for i := 0; i < len(a); i++ {
		// Ensure there are at least three elements to check
		if i+1 < len(a) && i+2 < len(a) {
			// Check if the current, next, and the one after next integers are consecutive
			if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
				found = true // Set found to true if consecutive triplet is found
			}
		}
	}

	// Output "YES" if a triplet was found, otherwise output "NO"
	if found {
		writer.WriteString("YES\n")
	} else {
		writer.WriteString("NO\n")
	}
}

// Helper function to remove duplicates from a slice
func unique(intSlice []int) []int {
	keys := make(map[int]bool)
	list := []int{}
	for _, entry := range intSlice {
		if _, value := keys[entry]; !value {
			keys[entry] = true
			list = append(list, entry)
		}
	}
	return list
}

