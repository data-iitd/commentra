
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers from input: n (total items) and m (number of groups)
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	n, _ := strconv.Atoi(string(line[:len(line)-1]))
	line, _, _ = reader.ReadLine()
	m, _ := strconv.Atoi(string(line[:len(line)-1]))

	// Calculate the quotient (q) and remainder (r) when n is divided by m
	q := n / m  // Number of items each group will get
	r := n % m   // Remaining items after equal distribution

	// Create a slice 'a' initialized with'm' elements, each set to the quotient 'q'
	a := make([]int, m)
	for i := 0; i < m; i++ {
		a[i] = q
	}

	// Distribute the remainder 'r' among the first 'r' groups
	for i := 0; i < r; i++ {
		a[i]++ // Increment the count for the first 'r' groups by 1
	}

	// Print the final distribution of items in each group
	for i := 0; i < m; i++ {
		fmt.Printf("%d ", a[i]) // Print each group's item count on the same line
	}
	fmt.Println() // Add a newline at the end
}
