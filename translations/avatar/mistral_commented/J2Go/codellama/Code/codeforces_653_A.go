
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
	// Create a new Scanner object for reading input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the list from the user input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Create a slice to store the unique and sorted list elements
	a := make([]int, 0)
	for i := 0; i < n; i++ {
		// Read the next input value
		scanner.Scan()
		value, _ := strconv.Atoi(scanner.Text())
		a = append(a, value)
	}

	// Filter and sort the slice using Go sort package
	sort.Ints(a)
	a = a[:len(a)-1]

	// Check if there exists a sequence of three consecutive elements with a difference of 1
	found := false
	for i := 0; i < len(a); i++ {
		if i+1 < len(a) && i+2 < len(a) {
			if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
				found = true
				break
			}
		}
	}

	// Write the output to the console
	fmt.Println(strings.ToUpper(strconv.FormatBool(found)))
}

