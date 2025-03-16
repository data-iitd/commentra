
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of characters in the string and the number of queries
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	q, _ := strconv.Atoi(read(reader))

	// Read the input string
	s := read(reader)

	// Read the queries, each containing two integers l and r
	problems := make([][2]int, q)
	for i := 0; i < q; i++ {
		l, _ := strconv.Atoi(read(reader))
		r, _ := strconv.Atoi(read(reader))
		problems[i] = [2]int{l, r}
	}

	// Define a function to count occurrences of 'AC' in the string
	count := func(total int, i int) int {
		// Increment total if the substring from index i-1 to i is 'AC'
		if s[i-1:i+1] == "AC" {
			return total + 1
		}
		return total
	}

	// Create a cumulative sum list to keep track of 'AC' occurrences
	cumsum := make([]int, n)
	cumsum[0] = count(0, 1)
	for i := 1; i < n; i++ {
		cumsum[i] = count(cumsum[i-1], i+1)
	}

	// Process each query to find the number of 'AC' occurrences in the specified range
	for _, p := range problems {
		l, r := p[0], p[1]
		// Output the difference in cumulative sums to get the count in the range [l, r]
		fmt.Println(cumsum[r-1] - cumsum[l-1])
	}
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	return s[:len(s)-1]
}

