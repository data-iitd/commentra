
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function prototypes for stack operations
func push(x int) {
	stack = append(stack, x)
}

func pop() int {
	x := stack[len(stack)-1]
	stack = stack[:len(stack)-1]
	return x
}

var stack []int

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		if line == "+" {
			b := pop()
			a := pop()
			push(a + b)
		} else if line == "-" {
			b := pop()
			a := pop()
			push(a - b)
		} else if line == "*" {
			b := pop()
			a := pop()
			push(a * b)
		} else {
			n, _ := strconv.Atoi(line)
			push(n)
		}
	}
	fmt.Println(pop())
}

// Translate the above Go code to C and end with comment "