
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])

	// Read the list 't' and prepend a 0 for 1-based indexing
	t := make([]int, n+1)
	for i, v := range bufio.NewReader(os.Stdin).ReadLine()[2:] {
		t[i+1], _ = strconv.Atoi(string(v))
	}

	// Read the list 'a' and prepend a 0 for 1-based indexing
	a := make([]int, n+1)
	for i, v := range bufio.NewReader(os.Stdin).ReadLine()[2:] {
		a[i+1], _ = strconv.Atoi(string(v))
	}

	// Initialize the answer list and a count list to track occurrences
	ans, cnt := []int{}, make([]int, n+1)

	// Count the occurrences of each element in list 'a'
	for i := 1; i <= n; i++ {
		cnt[a[i]]++
	}

	// Iterate through each index from 1 to n
	for i := 1; i <= n; i++ {
		// Check if the current element in 't' is 1
		if t[i] == 1 {
			// Initialize a current path list starting with the current index
			crt := []int{i}
			// Set x to the corresponding value in 'a'
			x := a[i]

			// Continue to follow the chain while the count of x is 1
			for cnt[x] == 1 {
				crt = append(crt, x) // Add x to the current path
				x = a[x]              // Move to the next index in the chain
			}

			// Update the answer if the current path is longer than the previous answer
			if len(crt) > len(ans) {
				ans = crt[:] // Store a copy of the current path
			}
		}
	}

	// Reverse the answer list to maintain the original order
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}

	// Print the length of the longest path found
	fmt.Println(len(ans))

	// Print the elements of the longest path as a space-separated string
	for _, v := range ans {
		fmt.Printf("%d ", v)
	}
	fmt.Println()
}
