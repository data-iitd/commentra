
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	// Reading the number of inputs
	n, _ := strconv.Atoi(read(1)[0])

	// Processing the input based on the value of n
	if n == 1 {
		// Outputting "Hello World" if n is 1
		fmt.Println("Hello World")
	} else {
		// Reading two strings and calculating their sum if n is not 1
		strs := read(2)
		fmt.Println(strconv.Atoi(strs[0]) + strconv.Atoi(strs[1]))
	}
}

// Method to read input from the standard input stream
func read(len int) []string {
	strList := make([]string, 0)
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < len; i++ {
		scanner.Scan()
		strList = append(strList, scanner.Text())
	}
	return strList
}

// Method to close the BufferedReader if it is open
func close() {
	// Nothing to do here
}

// 