
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read height and width of the grid
	reader := bufio.NewReader(os.Stdin)
	h, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	w, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize a temporary character array and the target string
	t := make([]string, h)
	s := "snuke"

	// Iterate through the grid to find the target string
	for i := 0; i < h; i++ {
		t[i] = readLine(reader)
		if t[i] == s {
			// If found, calculate the position and print it
			c := 'A' + i
			fmt.Println(string(c) + strconv.Itoa(i+1))
			return // Exit the program after finding the target
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

// Return 0 to indicate successful execution
