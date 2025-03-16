package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Create an instance of TaskC to solve the problem
	var solver TaskC
	// Call the solve method with test number 1
	solver.solve(1, reader, writer)
}

type TaskC struct{}

func (tc TaskC) solve(testNumber int, reader *bufio.Reader, writer *bufio.Writer) {
	// Read the number of strings
	var n int
	fmt.Fscan(reader, &n)

	// Initialize an array to count occurrences of specific starting letters
	var cnt [5]int64

	// Process each string input
	for i := 0; i < n; i++ {
		var str string
		fmt.Fscan(reader, &str)
		// Increment the count based on the first character of the string
		switch str[0] {
		case 'M':
			cnt[0]++
		case 'A':
			cnt[1]++
		case 'R':
			cnt[2]++
		case 'C':
			cnt[3]++
		case 'H':
			cnt[4]++
		}
	}

	// Calculate the result based on combinations of counts
	var res int64 = 0
	res += cnt[0] * cnt[1] * cnt[2]
	res += cnt[0] * cnt[1] * cnt[3]
	res += cnt[0] * cnt[1] * cnt[4]
	res += cnt[0] * cnt[2] * cnt[3]
	res += cnt[0] * cnt[2] * cnt[4]
	res += cnt[0] * cnt[3] * cnt[4]
	res += cnt[1] * cnt[2] * cnt[3]
	res += cnt[1] * cnt[2] * cnt[4]
	res += cnt[1] * cnt[3] * cnt[4]
	res += cnt[2] * cnt[3] * cnt[4]

	// Output the result
	fmt.Fprintln(writer, res)
}

