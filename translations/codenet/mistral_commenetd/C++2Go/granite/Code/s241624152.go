

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read input values from the user
	a, _ := strconv.Atoi(read(reader))
	b, _ := strconv.Atoi(read(reader))

	// Initialize output string
	ans := ""

	// Determine the answer based on the input values
	if a == 1 && b == 1 {
		// Both a and b are equal to 1, so the answer is a draw
		ans = "Draw"
	} else if a == 1 {
		// a is equal to 1, so the answer is Alice
		ans = "Alice"
	} else {
		// Neither a nor b is equal to 1, so the answer is Bob
		ans = "Bob"
	}

	// Print the answer to the console
	fmt.Println(ans)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

