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

	testNumber := 1
	solver := NewBUnhappyHackingABCEdit()

	solver.solve(testNumber, in, out)
}

type LightScanner struct {
	reader *bufio.Reader
}

func NewLightScanner(in io.Reader) *LightScanner {
	return &LightScanner{reader: bufio.NewReader(in)}
}

func (ls *LightScanner) String() string {
	line, err := ls.reader.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(line)
}

type BUnhappyHackingABCEdit struct{}

func NewBUnhappyHackingABCEdit() *BUnhappyHackingABCEdit {
	return &BUnhappyHackingABCEdit{}
}

func (solver *BUnhappyHackingABCEdit) solve(testNumber int, in *LightScanner, out io.Writer) {
	s := in.String()
	var d strings.Builder

	for _, c := range s {
		switch c {
		case '0':
			d.WriteRune('0')
		case '1':
			d.WriteRune('1')
		case 'B':
			if d.Len() > 0 {
				d.Truncate(d.Len() - 1)
			}
		}
	}

	out.Write([]byte(d.String()))
}

