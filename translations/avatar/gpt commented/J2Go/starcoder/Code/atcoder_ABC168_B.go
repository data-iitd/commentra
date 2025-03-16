package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input from stdin
	input, _ := reader.ReadString('\n')

	// Convert the input string into a slice of strings by splitting it on whitespace
	inputSlice := strings.Split(input, " ")

	// Convert the first element of the slice to an integer
	K, _ := strconv.Atoi(inputSlice[0])

	// Convert the second element of the slice to a string
	S := inputSlice[1]

	// Check if the length of the string S is less than or equal to K
	if len(S) <= K {
		// If true, print the string S as it is
		fmt.Println(S)
	} else {
		// If false, print the first K characters of S followed by "..."
		fmt.Println(S[:K] + "...")
	}
}

