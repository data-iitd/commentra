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

	solver := NewCColoringColorfully()
	solver.solve(1, in, out)
}

type CColoringColorfully struct{}

func NewCColoringColorfully() *CColoringColorfully {
	return &CColoringColorfully{}
}

func (c *CColoringColorfully) solve(testNumber int, in *InputReader, out *bufio.Writer) {
	x := in.next()
	a := []rune(x)
	b := []rune(x)
	a1 := 0
	a2 := 0
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
	fmt.Fprintln(out, min(a1, a2))
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(stream interface{}) *InputReader {
	return &InputReader{reader: bufio.NewReader(os.Stdin)}
}

func (ir *InputReader) next() string {
	for {
		line, err := ir.reader.ReadString('\n')
		if err == nil {
			return strings.TrimSpace(line)
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

