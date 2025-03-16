package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
	in := bufio.NewScanner(os.Stdin)

	// Read the number of elements
	in.Scan()
	n, _ := strconv.Atoi(in.Text())

	// Initialize an array to store the elements
	ara := make([]int, n)

	// Create a map to count the frequency of each element
	m := make(map[int]int)

	// Read elements and populate the frequency map
	for i := 0; i < n; i++ {
		in.Scan()
		v, _ := strconv.Atoi(in.Text())
		ara[i] = v
		// If the element is not in the map, add it with a count of 1
		if _, ok := m[v];!ok {
			m[v] = 1
		} else {
			// If it is already in the map, increment its count
			m[v] = m[v] + 1
		}
	}

	// Find the maximum frequency among the elements
	max := 0
	for _, i := range m {
		max = max + i
	}

	// Create another map to track the order of elements while checking frequency
	mm := make(map[int]int)

	// Iterate through the original array to find the first element with maximum frequency
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]];!ok {
			mm[ara[i]] = 1
			// Check if the current element's frequency matches the maximum frequency
			if mm[ara[i]] == max {
				fmt.Println(ara[i])
				break
			}
		} else {
			// Increment the count for the existing element
			mm[ara[i]] = mm[ara[i]] + 1
			// Check if the current element's frequency matches the maximum frequency
			if mm[ara[i]] == max {
				fmt.Println(ara[i])
				break
			}
		}
	}
}

// 