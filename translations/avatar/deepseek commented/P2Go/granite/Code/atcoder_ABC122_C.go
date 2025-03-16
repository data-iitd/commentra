

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the length of the string and the number of queries
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	q, _ := strconv.Atoi(reader.ReadLine()[2:])

	// Read the string
	s := reader.ReadLine()[2:]

	// Define a function to count occurrences of 'AC' in the string
	count := func(total int, i int) int {
		// Check if the current substring is 'AC'
		if string(s[i-1:i+1]) == "AC" {
			// Increment the count if 'AC' is found
			return total + 1
		} else {
			// Return the total count if 'AC' is not found
			return total
		}
	}

	// Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
	cumsum := make([]int, n)
	cumsum[0] = 0
	for i := 1; i < n; i++ {
		cumsum[i] = cumsum[i-1] + count(0, i)
	}

	// Iterate over the queries and print the difference in cumulative sums
	for i := 0; i < q; i++ {
		l, _ := strconv.Atoi(reader.ReadLine()[2:])
		r, _ := strconv.Atoi(reader.ReadLine()[2:])
		fmt.Println(cumsum[r-1] - cumsum[l-1])
	}
}
