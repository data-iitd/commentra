package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scanf("%d", &n)

	// Initialize arrays to store input values and counts
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	// Read values into array a
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	// Read values into array b
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &b[i])
	}

	// Count occurrences of each value in array b
	for i := 1; i <= n; i++ {
		num[b[i]]++
	}

	// Initialize variables for tracking the longest sequence and its representation
	ss := ""
	ans := 0
	st := make([]bool, n+1)

	// Iterate through each element to find the longest valid sequence
	for i := 1; i <= n; i++ {
		// Check if the current element in a is 1
		if a[i] == 1 {
			st[i] = true // Mark this index as visited
			var sb strings.Builder
			x := b[i] // Start with the corresponding value in b
			var sss strings.Builder
			sss.WriteString(strconv.Itoa(i)) // Append the current index
			sb.WriteString(" " + sss.String()[::-1]) // Reverse and append to the sequence

			s := 1 // Initialize the length of the current sequence

			// Continue to build the sequence while conditions are met
			for!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1 {
				sss = strings.Builder{}
				sss.WriteString(strconv.Itoa(x)) // Append the next index
				sb.WriteString(" " + sss.String()[::-1]) // Reverse and append to the sequence
				st[x] = true // Mark this index as visited
				x = b[x] // Move to the next index in b
				s++ // Increment the sequence length
			}

			// Update the longest sequence found if the current one is longer
			if s > ans {
				ans = s
				ss = sb.String()[::-1] // Store the longest sequence
			}
		}
	}

	// Output the length of the longest sequence and the sequence itself
	fmt.Println(ans)
	fmt.Println(ss)
}

