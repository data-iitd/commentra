package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var x string
	fmt.Fscan(reader, &x)

	solver := CColoringColorfully{}
	solver.solve(x, writer)
}

type CColoringColorfully struct{}

func (c *CColoringColorfully) solve(x string, writer *bufio.Writer) {
	a := []rune(x)
	b := []rune(x)
	a1, a2 := 0, 0

	// First loop to change characters to make the string colorful
	for i := 1; i < len(a); i++ {
		if a[i] == a[i-1] {
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			a1++
		}
	}

	// Second loop to change characters to make the string colorful
	for i := len(b) - 1; i > 0; i-- {
		if b[i] == b[i-1] {
			if b[i-1] == '1' {
				b[i-1] = '0'
			} else {
				b[i-1] = '1'
			}
			a2++
		}
	}

	// Output the minimum number of changes needed
	if a1 < a2 {
		fmt.Fprintln(writer, a1)
	} else {
		fmt.Fprintln(writer, a2)
	}
}

// <END-OF-CODE>
