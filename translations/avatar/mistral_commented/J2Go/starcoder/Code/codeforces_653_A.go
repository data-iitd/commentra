
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to check if there exists a sequence of three consecutive elements with a difference of 1
func checkSequence(a []int) bool {
	// Sort the list
	sort.Ints(a)

	// Iterate through the list
	for i := 0; i < len(a)-2; i++ {
		// Check if the next and next-next elements exist
		if i+1 < len(a) && i+2 < len(a) {
			// Check if the difference is 1
			if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
				return true
			}
		}
	}

	return false
}

func main() {
	// Read the number of elements in the list from the user input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements in the list: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Create an array to store the unique and sorted list elements
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Print("Enter the next element: ")
		input, _ = reader.ReadString('\n')
		a[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Check if there exists a sequence of three consecutive elements with a difference of 1
	found := checkSequence(a)

	// Write the output to the console
	fmt.Println(found)
}

