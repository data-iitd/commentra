package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new reader to read input from the standard input stream
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input, split by spaces, and store in an array of strings
	str, _ := reader.ReadString('\n')
	strSlice := strings.Split(strings.TrimSpace(str), " ")

	// Create a new scanner to parse the next line of input as integers
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nums := strings.Split(scanner.Text(), " ")

	// Parse the first integer from the tokenized input
	a, _ := strconv.Atoi(nums[0])

	// Parse the second integer from the tokenized input
	b, _ := strconv.Atoi(nums[1])

	// Read another string from the input
	u, _ := reader.ReadString('\n')
	u = strings.TrimSpace(u)

	// Check if the read string is equal to the first element of the array and print accordingly
	if u == strSlice[0] {
		fmt.Println(strconv.Itoa(a-1) + " " + strconv.Itoa(b))
	} else {
		fmt.Println(strconv.Itoa(a) + " " + strconv.Itoa(b-1))
	}
}

