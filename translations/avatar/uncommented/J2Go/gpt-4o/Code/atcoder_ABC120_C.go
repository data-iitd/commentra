package main

import (
	"bufio"
	"fmt"
	"os"
)

type TaskB struct{}

func (t *TaskB) solve(x string) int {
	stack := []rune{}
	c := 0

	for _, char := range x {
		stack = append(stack, char)
		for len(stack) > 1 {
			p := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			q := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++
				continue
			} else {
				stack = append(stack, q)
				stack = append(stack, p)
				break
			}
		}
	}
	return c * 2
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var x string
	fmt.Fscan(reader, &x)

	solver := TaskB{}
	result := solver.solve(x)

	fmt.Fprintln(writer, result)
	writer.Flush()
}

// <END-OF-CODE>
