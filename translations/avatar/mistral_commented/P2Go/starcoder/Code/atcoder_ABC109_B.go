package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	// Read the number of elements in the list from user input
	var n int
	fmt.Scanf("%d\n", &n)

	// Initialize an empty map's'
	s := make(map[string]int)

	// Create an empty list 'l' with length 'n' by reading elements from user input
	l := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s\n", &l[i])
	}

	// Initialize a flag 'f' with value 'Yes'
	f := "Yes"

	// Iterate through each element 'v' in the list 'l'
	for i, v := range l {
		// Increment the count of 'v' in map's'
		s[v]++

		// Check if the count of 'v' in map's' is greater than or equal to 2
		if s[v] >= 2 {
			// If yes, set the flag 'f' to 'No'
			f = "No"
		}

		// Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
		if i!= -1 && l[i][len(l[i])-1]!= v[0] {
			// If yes, set the flag 'f' to 'No'
			f = "No"
		}
	}

	// Print the final value of flag 'f'
	fmt.Println(f)
}

