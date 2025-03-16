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

	// Function definition for counting the number of 'AC' substrings in the given string 's'
	// The function takes two arguments: 'total' which is the current sum of 'AC' substrings and 'i' which is the index of the current character
	count := func(total int, i int) int {
		// Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
		if s[i-1:i+1] == "AC" {
			return total + 1
		}
		return total
	}

	// Using accumulate function to calculate the cumulative sum of 'AC' substrings in the string 's'
	cumsum := make([]int, n+1)
	cumsum[0] = 0
	for i := 1; i <= n; i++ {
		cumsum[i] = count(cumsum[i-1], i)
	}

	// Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
	for _, problem := range problems {
		l, r := problem[0], problem[1]
		// Print the difference between the cumulative sum at the end and start of the problem
		fmt.Fprintln(writer, cumsum[r-1]-cumsum[l-1])
	}
}
