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

	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1] // Remove the newline character

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

	// Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
	cumsum := make([]int, n+1)
	cumsum[0] = 0
	for i := 1; i <= n; i++ {
		cumsum[i] = cumsum[i-1]
		if i > 1 && s[i-2:i] == "AC" {
			cumsum[i]++
		}
	}

	// Iterate over the queries and print the difference in cumulative sums
	for _, query := range problems {
		l, r := query[0], query[1]
		fmt.Fprintln(writer, cumsum[r-1]-cumsum[l-1])
	}
}

