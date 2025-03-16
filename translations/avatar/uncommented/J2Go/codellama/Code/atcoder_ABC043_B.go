
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
	in := newLightScanner(inputStream)
	out := newPrintWriter(outputStream)
	solver := newBUnhappyHackingABCEdit()
	solver.solve(1, in, out)
	out.close()
}

type BUnhappyHackingABCEdit struct{}

func (solver *BUnhappyHackingABCEdit) solve(testNumber int, in *lightScanner, out *printWriter) {
	s := in.string()
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
				d.Reset()
			}
		}
	}
	out.println(d.String())
}

type lightScanner struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

func newLightScanner(in io.Reader) *lightScanner {
	return &lightScanner{
		reader: bufio.NewReader(in),
	}
}

func (in *lightScanner) string() string {
	if in.tokenizer == nil || !in.tokenizer.Scan() {
		in.tokenizer = strings.NewTokenizer(in.reader.ReadString('\n'))
	}
	return in.tokenizer.Token()
}

type printWriter struct {
	writer *bufio.Writer
}

func newPrintWriter(out io.Writer) *printWriter {
	return &printWriter{
		writer: bufio.NewWriter(out),
	}
}

func (out *printWriter) println(s string) {
	fmt.Fprintln(out.writer, s)
}

func (out *printWriter) close() {
	out.writer.Flush()
}

