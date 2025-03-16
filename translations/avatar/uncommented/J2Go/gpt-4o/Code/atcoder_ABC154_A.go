package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the first line and split it into a slice of strings
	str, _ := reader.ReadString('\n')
	strSlice := strings.Fields(str)

	// Read the second line and parse the integers
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)
	a, _ := strconv.Atoi(tokens[0])
	b, _ := strconv.Atoi(tokens[1])

	// Read the third line
	u, _ := reader.ReadString('\n')
	u = strings.TrimSpace(u)

	// Compare and print the result
	if u == strSlice[0] {
		fmt.Printf("%d %d\n", a-1, b)
	} else {
		fmt.Printf("%d %d\n", a, b-1)
	}
}

// <END-OF-CODE>
