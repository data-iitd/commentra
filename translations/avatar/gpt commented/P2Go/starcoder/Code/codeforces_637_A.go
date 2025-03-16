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
	// Read the number of elements
	var n int
	fmt.Scanf("%d\n", &n)

	// Read the input string, remove the last character (newline), and split it into a list
	s := strings.Split(strings.TrimSuffix(bufio.NewReader(os.Stdin).ReadString(), "\n"), " ")

	// Count the occurrences of each element in the list
	w := make(map[string]int)
	for _, v := range s {
		w[v]++
	}

	// Reverse the list to process elements in reverse order
	s = s[::-1]

	// Initialize variables to track the index of the most frequent element and its value
	c, a := -1, 0

	// Iterate through each unique element in the count dictionary
	for i := range w {
		// Check if the current element's count is equal to the maximum count
		if w[i] == max(w) {
			// If the index of the current element in the reversed list is greater than the current index
			if strings.Index(string(s), i) > c {
				// Update the most frequent element and its index
				a = i
				c = strings.Index(string(s), i)
			}
		}
	}

	// Print the most frequent element that appears last in the original order
	fmt.Println(a)
}

