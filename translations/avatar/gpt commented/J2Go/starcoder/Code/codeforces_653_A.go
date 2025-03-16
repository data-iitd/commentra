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
	// Use defer to ensure the file is always closed
	defer func() {
		if err := recover(); err!= nil {
			fmt.Println("Error:", err)
		}
		file.Close()
	}()

	// Open the input file
	file, err := os.Open("input.txt")
	if err!= nil {
		panic(err)
	}

	// Use defer to ensure the file is always closed
	defer file.Close()

	// Use bufio.NewScanner to read the file line by line
	scanner := bufio.NewScanner(file)

	// Use defer to ensure the file is always closed
	defer scanner.Close()

	// Read the number of integers from input
	n, err := strconv.Atoi(scanner.Text())
	if err!= nil {
		panic(err)
	}

	// Initialize a list to store the integers
	a := make([]int, n)

	// Read n integers from input and add them to the list
	for i := 0; i < n; i++ {
		a[i], err = strconv.Atoi(scanner.Text())
		if err!= nil {
			panic(err)
		}
	}

	// Remove duplicates, sort the list, and collect it back into a list
	a = removeDuplicates(a)
	sort.Ints(a)
	a = collect(a)

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
	fmt.Println(found)
}

// removeDuplicates removes duplicates from a list
func removeDuplicates(a []int) []int {
	// Use a map to store the unique integers
	m := make(map[int]bool)

	// Loop through the list and add the unique integers to the map
	for _, v := range a {
		m[v] = true
	}

	// Initialize a new list to store the unique integers
	b := make([]int, len(m))

	// Loop through the map and add the unique integers to the new list
	i := 0
	for k := range m {
		b[i] = k
		i++
	}

	return b
}

// collect collects the integers in a list into a new list
func collect(a []int) []int {
	// Initialize a new list to store the integers
	b := make([]int, len(a))

	// Loop through the list and add the integers to the new list
	for i, v := range a {
		b[i] = v
	}

	return b
}

