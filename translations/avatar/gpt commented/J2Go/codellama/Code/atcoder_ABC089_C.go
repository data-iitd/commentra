package main

import (
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	// Set up input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := bufio.NewScanner(inputStream)
	out := bufio.NewWriter(outputStream)

	// Create an instance of TaskC to solve the problem
	solver := TaskC{}
	// Call the solve method with test number 1
	solver.solve(1, in, out)

	// Close the output stream
	out.Flush()
}

type TaskC struct{}

func (solver *TaskC) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	// Read the number of strings
	n, _ := strconv.Atoi(in.Text())
	// Initialize an array to count occurrences of specific starting letters
	cnt := make([]int, 5)
	for i := 0; i < 5; i++ {
		cnt[i] = 0
	}

	// Process each string input
	for i := 0; i < n; i++ {
		str := in.Text()
		// Increment the count based on the first character of the string
		if str[0] == 'M' {
			cnt[0]++
		} else if str[0] == 'A' {
			cnt[1]++
		} else if str[0] == 'R' {
			cnt[2]++
		} else if str[0] == 'C' {
			cnt[3]++
		} else if str[0] == 'H' {
			cnt[4]++
		}
	}

	// Calculate the result based on combinations of counts
	res := cnt[0]*cnt[1]*cnt[2] + cnt[0]*cnt[1]*cnt[3] + cnt[0]*cnt[1]*cnt[4] + cnt[0]*cnt[2]*cnt[3] + cnt[0]*cnt[2]*cnt[4] + cnt[0]*cnt[3]*cnt[4] + cnt[1]*cnt[2]*cnt[3] + cnt[1]*cnt[2]*cnt[4] + cnt[1]*cnt[3]*cnt[4] + cnt[2]*cnt[3]*cnt[4]

	// Output the result
	fmt.Fprintln(out, res)
}

