
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read a line of input, split it into parts, and convert each part to an integer
	_input := func() []int {
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Scan()
		line := scanner.Text()
		parts := make([]int, 0)
		for _, part := range strings.Split(line, " ") {
			num, _ := strconv.Atoi(part)
			parts = append(parts, num)
		}
		return parts
	}

	// Read the values of n and m from input
	n, m := _input()

	// Read a list of integers from input
	lst := _input()

	// Initialize a dictionary to count occurrences of each integer in the list
	l := make(map[int]int)

	// Count the occurrences of each integer in the list
	for i := 0; i < n; i++ {
		l[lst[i]]++
	}

	// Initialize the result variable to store the final count
	res := 0

	// Calculate the result based on the occurrences of integers
	for i := 0; i < n; i++ {
		if l[lst[i]] > 1 {
			// If the current integer appears more than once
			res += n - i - l[lst[i]]  // Add the number of valid pairs
			l[lst[i]]--  // Decrease the count of this integer
		} else {
			// If the current integer appears only once
			res += n - i - 1  // Add the number of valid pairs for unique integers
		}
	}

	// Print the final result
	fmt.Println(res)
}

