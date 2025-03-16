package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := NewInputReader(inputStream)
	out := NewPrintWriter(outputStream)
	sol := new(Solution)
	sol.solve(in, out)
	out.close()
}

type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
		tokenizer: nil,
	}
}

func (in *InputReader) n() string {
	for in.tokenizer == nil || !in.tokenizer.Scan() {
		in.tokenizer = strings.NewTokenizer(in.reader.ReadString('\n'))
	}
	return in.tokenizer.Token()
}

func (in *InputReader) ni() int {
	return int(in.n())
}

type PrintWriter struct {
	writer *bufio.Writer
}

func NewPrintWriter(stream io.Writer) *PrintWriter {
	return &PrintWriter{
		writer: bufio.NewWriter(stream),
	}
}

func (out *PrintWriter) println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *PrintWriter) close() {
	out.writer.Flush()
}

type Solution struct {
}

func (sol *Solution) solve(in *InputReader, out *PrintWriter) {
	n := in.ni()
	k := in.ni()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = in.ni()
	}
	sort.Ints(a)
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}
	out.println(ans)
}

