
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	var A, B, K int64 // Declaring variables A, B, and K of type int64
	var x, y int64 // Declaring variables x and y of type int64

	reader := bufio.NewReader(os.Stdin) // Creating a new Reader to read from the standard input
	tokens := strings.Split(readLine(reader), " ") // Reading the first line of input and splitting it into tokens using the space character as a delimiter
	A, _ = strconv.ParseInt(tokens[0], 10, 64) // Parsing the first token into an int64 value and assigning it to variable A
	B, _ = strconv.ParseInt(tokens[1], 10, 64) // Parsing the second token into an int64 value and assigning it to variable B
	K, _ = strconv.ParseInt(tokens[2], 10, 64) // Parsing the third token into an int64 value and assigning it to variable K

	x = A // Assigning the value of A to x
	y = B // Assigning the value of B to y

	x = A - K // Subtracting K from A and assigning the result to x

	if x < 0 { // Checking if x is negative
		y = B + x // If x is negative, adding the absolute value of x to B and assigning the result to y
		x = 0 // Setting x to zero
	}

	if y < 0 { // Checking if y is negative
		y = 0 // If y is negative, setting it to zero
	}

	fmt.Println(x, y) // Printing the values of x and y separated by a space character
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine() // Reading a line of input from the Reader
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n") // Removing any trailing newlines from the string and returning it
}

