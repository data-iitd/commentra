package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a scanner for input
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	
	// Initialize arrays to store input values and counts
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)
	
	// Read values into array a
	for i := 1; i <= n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Read values into array b
	for i := 1; i <= n; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Count occurrences of each value in array b
	for i := 1; i <= n; i++ {
		num[b[i]]++
	}
	
	// Initialize variables for tracking the longest sequence and its representation
	var ss string
	var ans int
	st := make([]bool, n+1)
	
	// Iterate through each element to find the longest valid sequence
	for i := 1; i <= n; i++ {
		// Check if the current element in a is 1
		if a[i] == 1 {
			st[i] = true // Mark this index as visited
			sb := &strings.Builder{}
			sb.WriteString(strconv.Itoa(i)) // Append the current index
			sss := &strings.Builder{}
			sss.WriteString(strconv.Itoa(i)) // Append the current index
			
			s := 1 // Initialize the length of the current sequence
			
			// Continue to build the sequence while conditions are met
			for !st[b[i]] && num[b[i]] == 1 && b[i] != 0 && a[b[i]] != 1 {
				sb.WriteString(" " + sss.String()) // Append to the sequence
				st[b[i]] = true // Mark this index as visited
				i = b[i] // Move to the next index in b
				s++ // Increment the sequence length
			}
			
			// Update the longest sequence found if the current one is longer
			if s > ans {
				ans = s
				ss = sb.String() // Store the longest sequence
			}
		}
	}
	
	// Output the length of the longest sequence and the sequence itself
	fmt.Println(ans)
	fmt.Println(ss)
}
