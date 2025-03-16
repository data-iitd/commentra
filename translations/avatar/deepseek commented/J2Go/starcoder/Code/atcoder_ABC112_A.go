
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading the number of inputs
	n, _ := strconv.Atoi(readLine())

	// Processing the input based on the value of n
	if n == 1 {
		// Outputting "Hello World" if n is 1
		fmt.Println("Hello World")
	} else {
		// Reading two strings and calculating their sum if n is not 1
		strs := readStrings(2)
		fmt.Println(sum(strs))
	}
}

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(line))
	}
	panic(err)
}

func readStrings(n int) []string {
	var strs []string
	for i := 0; i < n; i++ {
		strs = append(strs, readLine())
	}
	return strs
}

func sum(strs []string) int {
	var sum int
	for _, s := range strs {
		sum += atoi(s)
	}
	return sum
}

func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

