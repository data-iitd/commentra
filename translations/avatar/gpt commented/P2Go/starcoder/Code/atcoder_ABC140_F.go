package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read a single integer from standard input
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Function to read a list of integers from standard input
func readInts() []int {
	var a []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	ints := strings.Split(scanner.Text(), " ")
	for _, v := range ints {
		i, _ := strconv.Atoi(v)
		a = append(a, i)
	}
	return a
}

func main() {
	// Read the number of elements
	n := readInt()

	// Read the list of integers, sort it in descending order
	s := readInts()
	sort.Slice(s, func(i, j int) bool { return s[i] > s[j] })

	// Initialize a flag list to track which elements have been used
	flag := make([]bool, len(s))

	// Initialize the current list with the largest element
	cur := []int{s[0]}

	// Mark the first element as used
	flag[0] = false

	// Iterate N times to build the current list
	for i := 0; i < n; i++ {
		j := 0  // Index for the current list
		jM := len(cur)  // Length of the current list

		// Try to find the next largest unused element
		for k := 0; k < len(s); k++ {
			// Check if the current element is unused and smaller than the last added element
			if!flag[k] && s[k] < cur[j] {
				cur = append(cur, s[k])  // Add the element to the current list
				j++  // Move to the next index in the current list
				flag[k] = true  // Mark this element as used

				// If we have added enough elements, break out of the loop
				if j == jM {
					break
				}
			}
		} else {
			// If we couldn't find a suitable element, return "No"
			fmt.Println("No")
			return
		}

		// Sort the current list in descending order for the next iteration
		sort.Slice(cur, func(i, j int) bool { return cur[i] > cur[j] })
	}

	// If we successfully built the list, return "Yes"
	fmt.Println("Yes")
}

// 