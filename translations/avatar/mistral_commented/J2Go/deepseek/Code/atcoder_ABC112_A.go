package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int

	// Reading the first line of input which contains the number of test cases
	n = read(1)[0]

	// Checking if the number of test cases is equal to 1
	if n == 1 {
		// If yes, printing "Hello World" as output
		fmt.Println("Hello World")
	} else {
		// If not, reading the next two lines of input which contain two integers
		strs := read(2)
		num1, _ := strconv.Atoi(strs[0]) // Storing the first integer in a variable 'num1'
		num2, _ := strconv.Atoi(strs[1]) // Storing the second integer in a variable 'num2'

		// Printing the sum of the two integers as output
		fmt.Println(num1 + num2)
	}
}

// A function to read input from the console and return it as a String array
func read(len int) []string {
	strList := []string{} // Creating an empty slice to store the input lines

	reader := bufio.NewReader(os.Stdin) // Creating a new bufio.Reader object for reading input

	// Reading 'len' number of lines from the console and adding them to the slice
	for i := 0; i < len; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		strList = append(strList, line)
	}

	return strList
}

