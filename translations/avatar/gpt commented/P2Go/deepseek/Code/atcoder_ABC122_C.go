package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, q int
	fmt.Fscan(reader, &n, &q)

	// Read the input string
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1] // Remove the newline character

	// Read the queries
	problems := make([][2]int, q)
	for i := 0; i < q; i++ {
		fmt.Fscan(reader, &problems[i][0], &problems[i][1])
	}

	// Define a function to count occurrences of 'AC' in the string
	count := func(total int, i int) int {
		if s[i-1:i+1] == "AC" {
			return total + 1
		}
		return total
	}

	// Create a cumulative sum list to keep track of 'AC' occurrences
	cumsum := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cumsum[i] = count(cumsum[i-1], i)
	}

	// Process each query to find the number of 'AC' occurrences in the specified range
	for _, query := range problems {
		l, r := query[0], query[1]
		// Output the difference in cumulative sums to get the count in the range [l, r]
		fmt.Fprintln(writer, cumsum[r-1]-cumsum[l-1])
	}
}

