package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading the number of inputs
	n := readInt(1)[0]

	// Processing the input based on the value of n
	if n == 1 {
		// Outputting "Hello World" if n is 1
		fmt.Println("Hello World")
	} else {
		// Reading two strings and calculating their sum if n is not 1
		strs := readString(2)
		num1, _ := strconv.Atoi(strs[0])
		num2, _ := strconv.Atoi(strs[1])
		fmt.Println(num1 + num2)
	}
}

// Function to read input from the standard input stream
func readInt(len int) []int {
	var intList []int
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < len; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		intList = append(intList, num)
	}
	return intList
}

// Function to read input from the standard input stream
func readString(len int) []string {
	var strList []string
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < len; i++ {
		scanner.Scan()
		strList = append(strList, scanner.Text())
	}
	return strList
}

