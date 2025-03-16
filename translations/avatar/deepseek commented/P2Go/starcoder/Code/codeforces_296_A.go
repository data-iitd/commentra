
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take an integer input representing the threshold
	n, _ := strconv.Atoi(readLine())

	// Take a space-separated string input and split it into a list
	m := strings.Split(readLine(), " ")

	// Initialize a boolean variable to check if the condition is possible
	possible := true

	// Iterate over the unique elements in the list `m`
	for _, i := range m {
		// Check if the count of the current element is greater than or equal to n / 2 + 1
		if strings.Count(m, i) >= n/2+1 {
			possible = false
			break
		}
	}

	// Print 'YES' if possible is True, otherwise print 'NO'
	fmt.Println("YES" if possible else "NO")
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	return string(line)
}

