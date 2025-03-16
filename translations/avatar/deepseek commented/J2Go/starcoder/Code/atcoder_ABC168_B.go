
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

	// Read K
	K, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Read S
	S := strings.TrimSpace(readLine(reader))

	// Check if the length of the string S is less than or equal to K
	if len(S) <= K {
		// If true, print the string S as it is
		fmt.Println(S)
	} else {
		// If false, truncate the string to the first K characters and append "..."
		fmt.Println(S[:K] + "...")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

