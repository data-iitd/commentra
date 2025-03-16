
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func s() {
	// Read input as a list of integers
	input_list := strings.Split(strings.TrimSpace(string(readLine())), " ")

	// Sort the input list in ascending order
	sort.Slice(input_list, func(i, j int) bool {
		return strconv.Itoa(i) < strconv.Itoa(j)
	})

	// Initialize a variable to store the result
	result := ""

	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(input_list); i++ {

		// Compare the current element with the previous one
		current_element, _ := strconv.Atoi(input_list[i])
		previous_element, _ := strconv.Atoi(input_list[i-1])

		// Check if the current element is less than twice the previous element
		// and if it is not equal to the previous element
		if current_element < previous_element*2 && current_element != previous_element {

			// If the condition is true, set the result to 'YES'
			result = "YES"

			// Break out of the loop since we have found the answer
			break
		}
	}

	// Print the result
	fmt.Println(result)
}

func readLine() string {
	var line string
	if _, err := fmt.Scan(&line); err == io.EOF {
		return ""
	}
	return line
}

func main() {
	s()
}

