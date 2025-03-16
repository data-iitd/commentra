
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input, split by spaces, and store in an array of strings.
	str := strings.Split(readLine(reader), " ")

	// Create a new string tokenizer to parse the next line of input as integers.
	st := strings.Split(readLine(reader), " ")

	// Parse the first integer from the tokenized input.
	a, _ := strconv.Atoi(st[0])

	// Parse the second integer from the tokenized input.
	b, _ := strconv.Atoi(st[1])

	// Read another string from the input.
	u := readLine(reader)

	// Check if the read string is equal to the first element of the array and print accordingly.
	fmt.Println(u == str[0] && (a-1) + " " + fmt.Sprint(b) || a + " " + fmt.Sprint(b-1))
}

// readLine reads a single line from the buffered reader.
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

