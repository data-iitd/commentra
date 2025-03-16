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
	n, _ := strconv.Atoi(readLine(1)[0])

	// Check if the input is 1
	if n == 1 {
		// If the input is 1, print "Hello World"
		fmt.Println("Hello World")
	} else {
		// If the input is not 1, read two more strings
		strs := readLine(2)
		// Parse the two strings as integers and print their sum
		num1, _ := strconv.Atoi(strs[0])
		num2, _ := strconv.Atoi(strs[1])
		fmt.Println(num1 + num2)
	}
}

// Function to read a specified number of lines from input
func readLine(len int) []string {
	strList := []string{}
	scanner := bufio.NewScanner(os.Stdin)

	// Read 'len' lines from input
	for i := 0; i < len; i++ {
		scanner.Scan()
		strList = append(strList, scanner.Text())
	}

	return strList
}

