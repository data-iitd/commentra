
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	// Split the line into two strings
	n, q := strings.Split(line, " ")[0], strings.Split(line, " ")[1]

	// Convert the strings to integers
	n, q = strconv.Atoi(n), strconv.Atoi(q)

	// Read the second line of input
	line, err = reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	// Convert the string to a slice of runes
	s := []rune(line)

	// Create a slice of slices to store the start and end indices of each problem
	problems := make([][]int, q)

	// Iterate through each problem
	for i := 0; i < q; i++ {
		// Read the next line of input
		line, err = reader.ReadString('\n')
		if err!= nil {
			panic(err)
		}

		// Split the line into two strings
		l, r := strings.Split(line, " ")[0], strings.Split(line, " ")[1]

		// Convert the strings to integers
		l, r = strconv.Atoi(l), strconv.Atoi(r)

		// Append the start and end indices of the problem to the slice of slices
		problems[i] = []int{l, r}
	}

	// Create a slice to store the cumulative sum of 'AC' substrings
	cumsum := make([]int, n)

	// Iterate through each character in the string
	for i := 0; i < n; i++ {
		// If the substring from index 'i-1' to 'i+1' is 'AC', increment the cumulative sum by 1
		if s[i-1:i+1] == "AC" {
			cumsum[i] = cumsum[i-1] + 1
		} else {
			cumsum[i] = cumsum[i-1]
		}
	}

	// Iterate through each problem
	for _, problem := range problems {
		// Print the difference between the cumulative sum at the end and start of the problem
		fmt.Println(cumsum[problem[1]-1] - cumsum[problem[0]-1])
	}
}

