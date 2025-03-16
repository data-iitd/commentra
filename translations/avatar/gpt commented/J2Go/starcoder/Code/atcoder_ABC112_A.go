package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the first input as an integer
	n, _ := strconv.Atoi(readLine())

	// Check if the input is 1
	if n == 1 {
		// If the input is 1, print "Hello World"
		fmt.Println("Hello World")
	} else {
		// If the input is not 1, read two more strings
		strs := readLines(2)
		// Parse the two strings as integers and print their sum
		fmt.Println(strconv.Atoi(strs[0]) + strconv.Atoi(strs[1]))
	}
}

// Method to read a specified number of lines from input
func readLines(n int) []string {
	var strs []string
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		scanner.Scan()
		strs = append(strs, scanner.Text())
	}
	return strs
}

// Method to read a single line from input
func readLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

