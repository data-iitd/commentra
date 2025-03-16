
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
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Read the list of integers
	l := readLine(reader)
	split := strings.Split(l, " ")
	var a []int
	for _, s := range split {
		i, _ := strconv.Atoi(s)
		a = append(a, i)
	}

	// Initialize a variable to track unique counts
	f := 1 // Starting count for unique elements
	a = sort(a)

	// Initialize a counter for unique elements
	c := 0 // Counter for unique elements

	// Iterate through the sorted list to count unique elements
	for _, i := range a {
		if i > c { // Check if the current element is greater than the counter
			c++ // Increment the counter for unique elements
		}
	}

	// Output the total count of unique elements
	fmt.Println(c + 1) // Print the count of unique elements (including the first element)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
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

