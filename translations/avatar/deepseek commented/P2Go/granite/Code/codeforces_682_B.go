
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define input functions
var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(read())

	// Read the list of elements
	l := read_array()

	// Initialize variables
	f := 1  // Flag variable
	l = sort(l)  // Sort the list
	c := 0  // Counter variable

	// Iterate through the list to find the maximum number of unique elements
	for _, i := range l {
		if i > c {
			c++  // Increment the counter if the current element is greater than the counter
		}
	}

	// Print the result
	fmt.Println(c + 1)  // Print the maximum number of unique elements
}

func read() string {
	s, _ := in.ReadString('\n')
	return strings.TrimSpace(s)
}

func read_array() []int {
	s := read()
	s2 := strings.Split(s, " ")
	a := make([]int, len(s2))
	for i, v := range s2 {
		a[i], _ = strconv.Atoi(v)
	}
	return a
}

func sort(a []int) []int {
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if a[i] > a[j] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}
	return a
}

// 