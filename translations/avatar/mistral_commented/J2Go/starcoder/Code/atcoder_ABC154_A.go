
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {

	// Creating a new buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading the first line of input as an array of strings
	str := strings.Split(strings.TrimSpace(readLine(reader)), " ")

	// Creating a new string tokenizer to read the second line of input as separate tokens
	tokenizer := strings.Split(strings.TrimSpace(readLine(reader)), " ")

	// Reading the first two integers as input
	a, _ := strconv.Atoi(tokenizer[0])
	b, _ := strconv.Atoi(tokenizer[1])

	// Reading the third line of input as a string
	u := readLine(reader)

	// Checking if the first string from the first line matches with the given string 'u'
	if u == str[0] {

		// If the condition is true, then print the result as (a-1) and b
		fmt.Printf("%d %d\n", a-1, b)

	} else {

		// If the condition is false, then print the result as a and (b-1)
		fmt.Printf("%d %d\n", a, b-1)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

