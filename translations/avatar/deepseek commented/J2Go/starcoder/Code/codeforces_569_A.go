
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

	// Read the values of T, S, and q from the user input
	T, _ := strconv.Atoi(readLine(reader))
	S, _ := strconv.Atoi(readLine(reader))
	q, _ := strconv.Atoi(readLine(reader))

	// Initialize the variable `previous` with the value of S
	previous := S

	// Initialize the variable `answer` with the value 0
	answer := 0

	// Enter a while loop that continues until `previous` is less than T
	for previous < T {
		// Inside the loop, multiply `previous` by q and increment the `answer` by 1
		previous *= q
		answer++
	}

	// After the loop, print the value of `answer`
	fmt.Println(answer)
}

// readLine reads a string from stdin
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

