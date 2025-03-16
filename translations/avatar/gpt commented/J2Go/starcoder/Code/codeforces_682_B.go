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
	// Create a new Scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	fmt.Println("Enter the number of elements")
	n, _ := strconv.Atoi(reader.ReadString('\n'))

	// Initialize an array to store the input integers
	list := make([]int, n)

	// Read n integers from input and add them to the list
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element")
		list[i], _ = strconv.Atoi(reader.ReadString('\n'))
	}

	// Sort the list of integers in ascending order
	sort.Ints(list)

	// Initialize a counter to track the maximum consecutive integer
	c := 1

	// Iterate through the sorted list to find the maximum consecutive integer
	for i := 0; i < n; i++ {
		// If the current integer is greater than or equal to the counter, increment the counter
		if list[i] >= c {
			c++
		}
	}

	// Print the result which is the maximum consecutive integer found
	fmt.Println(c)
}

