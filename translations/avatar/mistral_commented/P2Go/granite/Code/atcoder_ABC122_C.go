
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Taking input for number of strings 'n' and number of problems 'q'
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readerReadLine(reader)[0])
	q, _ := strconv.Atoi(readerReadLine(reader)[0])

	// Taking input for the string's'
	s := readerReadLine(reader)[0]

	// List comprehension to create a list 'problems' of lists containing start and end indices of each problem
	problems := make([][]int, q)
	for i := 0; i < q; i++ {
		problems[i] = readerReadLineAsInt(reader)
	}

	// Function definition for counting the number of 'AC' substrings in the given string's'
	// The function takes two arguments: 'total' which is the current sum of 'AC' substrings and 'i' which is the index of the current character
	count := func(total, i int) int {
		// Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
		if s[i-1:i+1] == "AC" {
			return total + 1
		}
		return total
	}

	// Using accumulate function to calculate the cumulative sum of 'AC' substrings in the string's'
	cumsum := make([]int, n)
	cumsum[0] = 0
	for i := 1; i < n; i++ {
		cumsum[i] = count(cumsum[i-1], i)
	}

	// Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
	for _, problem := range problems {
		l, r := problem[0], problem[1]
		fmt.Println(cumsum[r-1] - cumsum[l-1])
	}
}

func readerReadLine(reader *bufio.Reader) []string {
	line, _, _ := reader.ReadLine()
	return strings.Split(string(line), " ")
}

func readerReadLineAsInt(reader *bufio.Reader) []int {
	line, _, _ := reader.ReadLine()
	return toIntSlice(strings.Split(string(line), " "))
}

func toIntSlice(s []string) []int {
	var x []int
	for _, num := range s {
		val, _ := strconv.Atoi(num)
		x = append(x, val)
	}
	return x
}

