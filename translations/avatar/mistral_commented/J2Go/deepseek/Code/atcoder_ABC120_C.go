package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := NewInputReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := TaskB{}
	solver.solve(in, out)
}

type TaskB struct{}

func (tb TaskB) solve(in *InputReader, out *bufio.Writer) {
	x := in.next()
	var s []rune
	c := 0

	for _, char := range x {
		s = append(s, char)

		for len(s) > 1 {
			p := s[len(s)-1]
			q := s[len(s)-2]
			s = s[:len(s)-2]

			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++
				continue
			}

			s = append(s, q)
			s = append(s, p)
			break
		}
	}

	fmt.Fprintln(out, c*2)
}

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(stream *os.File) *InputReader {
	scanner := bufio.NewScanner(stream)
	scanner.Split(bufio.ScanLines)
	return &InputReader{scanner: scanner}
}

func (ir *InputReader) next() string {
	ir.scanner.Scan()
	return ir.scanner.Text()
}

