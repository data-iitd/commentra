
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	n := 0 // n: number of heights
	fd := make([]int, 6) // fd: array to store counts
	height := 0.0 // height: variable to store each height input
	var err error // err: error variable
	var line string // line: input line
	var reader *bufio.Reader // reader: input reader
	var scanner *bufio.Scanner // scanner: input scanner
	var writer *bufio.Writer // writer: output writer

	// Initialize input and output
	reader = bufio.NewReader(os.Stdin)
	scanner = bufio.NewScanner(reader)
	writer = bufio.NewWriter(os.Stdout)

	// Read the number of heights
	fmt.Fscanf(reader, "%d\n", &n)

	// Loop to read each height and categorize it
	for i := 0; i < n; i++ {
		line, err = scanner.Scan()
		if err!= nil {
			fmt.Fprintln(os.Stderr, "Error reading input:", err)
			os.Exit(1)
		}
		height, err = strconv.ParseFloat(strings.TrimSpace(line), 64)
		if err!= nil {
			fmt.Fprintln(os.Stderr, "Error parsing input:", err)
			os.Exit(1)
		}
		if height >= 185.0 {
			fd[5]++
		} else if height >= 180.0 {
			fd[4]++
		} else if height >= 175.0 {
			fd[3]++
		} else if height >= 170.0 {
			fd[2]++
		} else if height >= 165.0 {
			fd[1]++
		} else {
			fd[0]++
		}
	}

	// Loop to print the histogram
	for i := 0; i < 6; i++ {
		fmt.Fprintf(writer, "%d:", i+1)
		for j := 0; j < fd[i]; j++ {
			fmt.Fprintf(writer, "*")
		}
		fmt.Fprintln(writer)
	}

	// Flush the output
	writer.Flush()
}
