package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the first input as an integer
	n, _ := strconv.Atoi(read(1)[0])

	// Check if the input is 1
	if n == 1 {
		// If the input is 1, print "Hello World"
		fmt.Println("Hello World")
	} else {
		// If the input is not 1, read two more strings
		strs := read(2)
		// Parse the two strings as integers and print their sum
		fmt.Println(strconv.Atoi(strs[0]) + strconv.Atoi(strs[1]))
	}
}

// Method to read a specified number of lines from input
func read(len int) []string {
	strList := make([]string, 0)
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < len; i++ {
		scanner.Scan()
		strList = append(strList, scanner.Text())
	}
	return strList
}

// Method to close the BufferedReader
func close() {
	// Close the BufferedReader if it is not null
	if scanner != nil {
		scanner.Close()
	}
}

// END-OF-CODE
