package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := NewLightScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	solver := NewBUnhappyHackingABCEdit()
	solver.solve(1, in, out)
}

type BUnhappyHackingABCEdit struct{}

func NewBUnhappyHackingABCEdit() *BUnhappyHackingABCEdit {
	return &BUnhappyHackingABCEdit{}
}

func (solver *BUnhappyHackingABCEdit) solve(testNumber int, in *LightScanner, out io.Writer) {
	s := in.string()
	var d strings.Builder
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

type LightScanner struct {
	scanner *bufio.Scanner
}

func NewLightScanner(in io.Reader) *LightScanner {
	scanner := bufio.NewScanner(in)
	scanner.Split(bufio.ScanWords)
	return &LightScanner{scanner: scanner}
}

func (in *LightScanner) string() string {
	if !in.scanner.Scan() {
		panic("unexpected EOF")
	}
	return in.scanner.Text()
}

