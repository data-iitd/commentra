package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type CColoringColorfully struct{}

func (c *CColoringColorfully) solve(x string) int {
	a := []rune(x)
	b := []rune(x)
	a1, a2 := 0, 0

	for i := 1; i < len(x); i++ {
		if a[i] == a[i-1] {
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			a1++
		}
	}

	for i := len(x) - 1; i > 0; i-- {
		if b[i] == b[i-1] {
			if b[i-1] == '1' {
				b[i-1] = '0'
			} else {
				b[i-1] = '1'
			}
			a2++
		}
	}

	return min(a1, a2)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	x, _ := reader.ReadString('\n')
	x = x[:len(x)-1] // Remove the newline character

	solver := CColoringColorfully{}
	result := solver.solve(x)
	fmt.Println(result)
}

// <END-OF-CODE>
