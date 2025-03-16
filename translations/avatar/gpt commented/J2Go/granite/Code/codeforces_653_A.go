
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Use bufio.Scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	// Read the number of integers from input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	// Initialize a slice to store the integers
	a := make([]int, n)
	// Read n integers from input and store them in the slice
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	// Sort the slice in ascending order
	sort.Ints(a)
	// Initialize a flag to check for consecutive triplets
	found := false
	// Check for three consecutive integers in the sorted slice
	for i := 0; i < len(a)-2; i++ {
		// Check if the current, next, and the one after next integers are consecutive
		if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
			found = true // Set found to true if consecutive triplet is found
		}
	}
	// Output "YES" if a triplet was found, otherwise output "NO"
	if found {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
