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
	// Use bufio.Scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)
	// Read the number of integers from input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	// Initialize a list to store the integers
	a := make([]int, 0)
	// Read n integers from input and add them to the list
	for i := 0; i < n; i++ {
		scanner.Scan()
		value, _ := strconv.Atoi(scanner.Text())
		a = append(a, value)
	}
	// Remove duplicates, sort the list, and collect it back into a list
	a = removeDuplicates(a)
	sort.Ints(a)
	// Initialize a flag to check for consecutive triplets
	found := false
	// Check for three consecutive integers in the sorted list
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
	fmt.Println(strings.ToUpper(strconv.FormatBool(found)))
}

// removeDuplicates removes duplicates from a list of integers
func removeDuplicates(a []int) []int {
	// Initialize a map to store unique integers
	m := make(map[int]bool)
	// Add each integer to the map
	for _, value := range a {
		m[value] = true
	}
	// Initialize a new list to store unique integers
	b := make([]int, 0)
	// Add each unique integer to the new list
	for key := range m {
		b = append(b, key)
	}
	return b
}

// 