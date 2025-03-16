
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Convert the string to an integer
	n, err := strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		panic(err)
	}
	// Read the second line
	line, err = reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Convert the string to an array of integers
	a := strings.Split(strings.TrimSpace(line), " ")
	for i := 0; i < len(a); i++ {
		a[i], err = strconv.Atoi(a[i])
		if err!= nil {
			panic(err)
		}
	}
	// Solve the problem
	fmt.Println(solve(n, a))
}

// Solve the problem
func solve(n int, a []int) int {
	// TODO: Solve the problem
	return 0
}

