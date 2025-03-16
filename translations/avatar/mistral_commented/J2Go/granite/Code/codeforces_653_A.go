

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Read the number of elements in the list from the user input
	n, _ := strconv.Atoi(read(in))

	// Create a slice to store the unique and sorted list elements
	a := make([]int, 0)
	for i := 0; i < n; i++ { // Iterate through the input elements
		value, _ := strconv.Atoi(read(in)) // Read the next input value
		a = append(a, value) // Add the value to the slice
	}

	// Sort the slice using the sort package
	sort.Ints(a)

	// Check if there exists a sequence of three consecutive elements with a difference of 1
	found := false
	for i := 0; i < len(a)-2; i++ { // Iterate through the slice elements
		if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] { // Check if the difference is 1
			found = true // Set the found flag if a sequence is found
			break // Exit the loop if a sequence is found
		}
	}

	// Write the output to the console
	fmt.Fprintln(out, "YES" if found else "NO")

	out.Flush() // Flush the output buffer
}

func read(in *bufio.Reader) string {
	str, _ := in.ReadString('\n') // Read a line of input from the console
	return str[:len(str)-1] // Return the input string without the trailing newline character
}

Translate the above Go code to C++ and end with comment "