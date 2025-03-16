
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// LightScanner is a class for reading input
type LightScanner struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

// NewLightScanner returns a new LightScanner
func NewLightScanner(in *os.File) *LightScanner {
	return &LightScanner{
		reader: bufio.NewReader(in),
	}
}

// String returns the next token
func (ls *LightScanner) String() string {
	if ls.tokenizer == nil ||!ls.tokenizer.Scan() {
		line, err := ls.reader.ReadString('\n')
		if err!= nil {
			panic(err)
		}
		ls.tokenizer = strings.NewTokenizer(line)
	}
	return ls.tokenizer.Token()
}

// BUnhappyHackingABCEdit is a class for solving the problem
type BUnhappyHackingABCEdit struct {
}

// NewBUnhappyHackingABCEdit returns a new BUnhappyHackingABCEdit
func NewBUnhappyHackingABCEdit() *BUnhappyHackingABCEdit {
	return &BUnhappyHackingABCEdit{}
}

// Solve solves the problem
func (b *BUnhappyHackingABCEdit) Solve(testNumber int, in *LightScanner, out *bufio.Writer) {
	s := in.String()
	d := make([]byte, 0)
	for _, c := range s {
		switch c {
		case '0':
			d = append(d, '0')
		case '1':
			d = append(d, '1')
		case 'B':
			if len(d) > 0 {
				d = d[:len(d)-1]
			}
		}
	}
	fmt.Fprintln(out, string(d))
}

func main() {
	testNumber := 1
	in := NewLightScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	solver := NewBUnhappyHackingABCEdit()
	solver.Solve(testNumber, in, out)
	out.Flush()
}

// 