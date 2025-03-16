
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading the number of test cases (t) and other required values
	reader := bufio.NewReader(os.Stdin)
	x, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	t, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	da, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	db, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Variables to store calculated values
	first := 0
	second := 0

	// Flag to determine if a solution is found
	ok := false

	// Nested loop to calculate possible values of first and second
	for i := 0; i < t; i++ {
		first = a - (da * i)
		for j := 0; j < t; j++ {
			second = b - (db * j)
			if second+first == x || second == x || first == x || x == 0 {
				// Check if the sum of first and second equals x, or if either value equals x, or if x is zero
				ok = true
				break
			}
		}
		if ok {
			break
		}
	}

	// Print the result based on the flag
	if ok {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

// Translate the above Java code to Go and end with comment "