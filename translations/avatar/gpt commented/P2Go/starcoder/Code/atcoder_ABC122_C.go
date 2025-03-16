package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of characters in the string and the number of queries
	n, q := readNums(os.Stdin)

	// Read the input string
	s := readString(os.Stdin)

	// Read the queries, each containing two integers l and r
	problems := make([][]int, q)
	for i := range problems {
		problems[i] = readNums(os.Stdin)
	}

	// Define a function to count occurrences of 'AC' in the string
	var count func(total int, i int) int
	count = func(total int, i int) int {
		// Increment total if the substring from index i-1 to i is 'AC'
		if i > 0 && s[i-1:i+1] == "AC" {
			total++
		}
		return total
	}

	// Create a cumulative sum list to keep track of 'AC' occurrences
	cumsum := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cumsum[i] = count(cumsum[i-1], i)
	}

	// Process each query to find the number of 'AC' occurrences in the specified range
	for _, problem := range problems {
		// Output the difference in cumulative sums to get the count in the range [l, r]
		l, r := problem[0], problem[1]
		fmt.Println(cumsum[r] - cumsum[l-1])
	}
}

func readString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

func readNums(reader *bufio.Reader) []int {
	line, _ := reader.ReadString('\n')
	nums := strings.Split(strings.TrimSpace(line), " ")
	numsInt := make([]int, 0, len(nums))
	for _, num := range nums {
		numInt, _ := strconv.Atoi(num)
		numsInt = append(numsInt, numInt)
	}
	return numsInt
}

