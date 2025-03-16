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
	// Create a new reader to read from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)

	// Parse n and k
	n, _ := strconv.Atoi(tokens[0])
	k, _ := strconv.Atoi(tokens[1])

	// Initialize a slice to hold the input numbers
	a := make([]int, n)

	// Read the next line of input for the array elements
	line, _ = reader.ReadString('\n')
	tokens = strings.Fields(line)

	// Parse the n integers and store them in the slice
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(tokens[i])
	}

	// Sort the slice in ascending order
	sort.Ints(a)

	// Initialize a variable to hold the sum of the smallest k elements
	ans := 0

	// Sum the first k elements of the sorted slice
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	// Output the result (sum of the smallest k elements)
	fmt.Println(ans)
}

// <END-OF-CODE>
