package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two values from input: one as an integer and the other as a float in string format
	sa, sb := strings.Split(strings.TrimSpace(readLine()), " ")

	// Convert the first value to an integer
	a, _ := strconv.Atoi(sa)

	// Convert the second value to an integer representing cents (by multiplying by 100)
	b, _ := strconv.Atoi(sb)

	// Calculate and print the product of a and b, divided by 100 to get the final result
	fmt.Println(a * b / 100)
}

// ReadLine reads a line from stdin and returns it as a string
func readLine() string {
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := os.Stdin.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return string(buf)
}

// 