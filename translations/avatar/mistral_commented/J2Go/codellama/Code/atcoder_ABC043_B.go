
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := bufio.NewScanner(inputStream)
	out := bufio.NewWriter(outputStream)

	testNumber := 1
	solver := BUnhappyHackingABCEdit{}

	solver.solve(testNumber, in, out)

	out.Flush()
}

type BUnhappyHackingABCEdit struct{}

func (solver *BUnhappyHackingABCEdit) solve(testNumber int, in *bufio.Scanner, out *bufio.Writer) {
	s := in.Text()
	d := strings.Builder{}

	for _, c := range s {
		switch c {
		case '0':
			d.WriteString("0")
		case '1':
			d.WriteString("1")
		case 'B':
			if d.Len() > 0 {
				d.Truncate(d.Len() - 1)
			}
		}
	}

	fmt.Fprintln(out, d.String())
}

// 